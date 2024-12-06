#include <iostream>
#include <map>
#include <unordered_map>
#include <tuple>
#include <utility>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>


// Tree reader and analyser for implant decay gamma analysis

bool is_overlapping(double imp_x, double imp_y, double imp_dx, double imp_dy,
                    double beta_x, double beta_y, double beta_dx, double beta_dy, double B) {
    return (imp_y + (imp_dy / 2.0) >= (beta_y - ((beta_dy / 2.0) + B)) &&
            imp_y - (imp_dy / 2.0) <= (beta_y + ((beta_dy / 2.0) + B)) &&
            imp_x + (imp_dx / 2.0) >= (beta_x - ((beta_dx / 2.0) + B)) &&
            imp_x - (imp_dx / 2.0) <= (beta_x + ((beta_dx / 2.0) + B)));
}

// Custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

void decaygamma(){

    // Load file
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_all_new.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_backg.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_all_new.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_doubles_e.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/166Tb_stupidmistake.root");
    TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/testdt2.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/166Tb_background.root");

    std::cout << "File loaded: "<< file->GetName() << std::endl;

    // Get the trees
    TTree* implant_tree = (TTree*)file->Get("aida_implant_tree");
    TTree* gatedimplant_tree = (TTree*)file->Get("aida_gatedimplant_tree");
    TTree* decay_tree = (TTree*)file->Get("aida_decay_tree");
    TTree* germanium_tree = (TTree*)file->Get("germanium_tree");

    // Open the output file
    TFile* outputFile = new TFile("implantdecay.root", "RECREATE");
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << std::endl;
        return;
    }

    // Set tree readers

    TTreeReader implant_reader(implant_tree);
    TTreeReader gatedimplant_reader(gatedimplant_tree);
    TTreeReader decay_reader(decay_tree);
    TTreeReader germanium_reader(germanium_tree);

    TTreeReaderValue<ULong64_t> implant_time(implant_reader, "implant.time");
    TTreeReaderValue<double> implant_x(implant_reader, "implant.x");
    TTreeReaderValue<double> implant_y(implant_reader, "implant.y");
    TTreeReaderValue<double> implant_e(implant_reader, "implant.e");
    TTreeReaderValue<double> implant_ex(implant_reader, "implant.ex");
    TTreeReaderValue<double> implant_ey(implant_reader, "implant.ey");
    TTreeReaderValue<Int_t> implant_spill(implant_reader, "implant.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> implant_bplast(implant_reader, "implant.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> gatedimplant_time(gatedimplant_reader, "gatedimplant.time");
    TTreeReaderValue<double> gatedimplant_x(gatedimplant_reader, "gatedimplant.x");
    TTreeReaderValue<double> gatedimplant_y(gatedimplant_reader, "gatedimplant.y");
    TTreeReaderValue<double> gatedimplant_e(gatedimplant_reader, "gatedimplant.e");
    TTreeReaderValue<double> gatedimplant_ex(gatedimplant_reader, "gatedimplant.ex");
    TTreeReaderValue<double> gatedimplant_ey(gatedimplant_reader, "gatedimplant.ey");
    TTreeReaderValue<Int_t> gatedimplant_spill(gatedimplant_reader, "gatedimplant.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> gatedimplant_bplast(gatedimplant_reader, "gatedimplant.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> decay_time(decay_reader, "decay.time");
    TTreeReaderValue<double> decay_x(decay_reader, "decay.x");
    TTreeReaderValue<double> decay_y(decay_reader, "decay.y");
    TTreeReaderValue<double> decay_e(decay_reader, "decay.e");
    TTreeReaderValue<double> decay_ex(decay_reader, "decay.ex");
    TTreeReaderValue<double> decay_ey(decay_reader, "decay.ey");
    TTreeReaderValue<Int_t> decay_spill(decay_reader, "decay.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> decay_bplast(decay_reader, "decay.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> germanium_time(germanium_reader, "germanium.time");
    TTreeReaderValue<Double_t> germanium_energy(germanium_reader, "germanium.energy");
    TTreeReaderValue<Int_t> germanium_spill(germanium_reader, "germanium.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> germanium_bplast(germanium_reader, "germanium.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired
    
    // Experiment information
    uint64_t wr_experiment_start = 1.7137464e+18;
    uint64_t wr_experiment_end = 1.7143668e+18;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 60; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    // half life of 166Dy
    double half_life = 27.1; // seconds
    int64_t half_life_ns = 27.1*1e9; // ns
    double total_time = half_life; // seconds
    int bins_per_half_life = 100;
    int number_of_bins = half_life*bins_per_half_life;


    // Histograms
    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", number_of_bins, -half_life*2,half_life*2);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);
    TH1F* germanium_decay_energy = new TH1F("germanium_decay_energy", "Germanium Decay Energy", 1.5e3, 0, 1.5e3);
    TH1F* germanium_aida_wr_dt = new TH1F("germanium_aida_wr_dt", "Germanium AIDA WR Time Difference", 1e3, -1e5, 1e5);
    TH1F* aida_implant_before_decay_counter = new TH1F("aida_implant_before_decay_counter", "AIDA Implant Before Decay Counter", 10, 0, 10);
    TH1F* aida_gatedimplant_before_decay_counter = new TH1F("aida_gatedimplant_before_decay_counter", "AIDA Gated Implant Before Decay Counter", 1e3, 0, 1e3);
    TH2F* aida_posdiff_time = new TH2F("aida_posdiff_time", "AIDA Position Difference vs Time", 1e3, 0, 1e3, 1e3, -1e4, 1e5);
    TH1F* aida_averageimplant_150s = new TH1F("aida_averageimplant_150s", "AIDA Average Implant 150s", number_of_slices, 0, duration_in_seconds);
    TH1F* aida_averagegatedimplant_150s = new TH1F("aida_averagegatedimplant_150s", "AIDA Average Gated Implant 150s", number_of_slices, 0, duration_in_seconds);
    TH1F* aida_implant_veto_dt = new TH1F("aida_implant_veto_dt", "AIDA Implant Veto Time Difference", 1e4, 0, 3e9);
    TH2F* aida_implant_dt_vs_pos_x = new TH2F("aida_implant_dt_vs_pos_x", "AIDA Implant-Decay Time Difference vs Position Difference X", 1e4, 0, 3e9, 384, 0, 384);
    TH2F* aida_implant_dt_vs_pos_y = new TH2F("aida_implant_dt_vs_pos_y", "AIDA Implant-Decay Time Difference vs Position Difference Y", 1e4, 0, 3e9, 384, 0, 384);
    TH2F* aida_implant_dt_vs_pos_diff = new TH2F("aida_implant_dt_vs_pos_diff", "AIDA Implant-Decay Time Difference vs Position Difference X-Y", 1e4, 0, 3e9, 384, 0, 384);


    // Make new maps for processing the data

    enum EventType { GATEDIMPLANT, IMPLANT, DECAY };

    std::map<int64_t, std::tuple<double, double, int, int>> implant_map;
    std::map<int64_t, std::tuple<double, double, int, int>> gatedimplant_map;
    std::map<int64_t, std::tuple<double, double, int, int>> decay_map;
    std::map<int64_t, std::tuple<double,int, int>> germanium_map;

    std::multimap<int64_t, std::tuple<double, double, int, int, EventType>> event_map;
    std::multimap<int64_t, std::tuple<double, double, int, int, EventType>> all_implants;
    std::multimap<int64_t, std::tuple<double, double, int, int, EventType>> good_decays;
    std::multimap<int64_t, std::tuple<double, double, int, int, EventType>> good_implants;

    // Loop over the implant and decay trees and fill the maps
    // std::cout << "Filling the maps" << std::endl;
    // while (implant_reader.Next()) {
    //     implant_map[*implant_time] = std::make_tuple(*implant_x, *implant_y, *implant_spill, *implant_bplast);
    // }
    // std::cout << "Finished filling the implant map" << std::endl;
    // while(gatedimplant_reader.Next()) {
    //     gatedimplant_map[*gatedimplant_time] = std::make_tuple(*gatedimplant_x, *gatedimplant_y, *gatedimplant_spill, *gatedimplant_bplast);
    // }
    // std::cout << "Finished filling the gated implant map" << std::endl;
    // while(decay_reader.Next()) {
    //     decay_map[*decay_time] = std::make_tuple(*decay_x, *decay_y, *decay_spill, *decay_bplast);
    // }
    std::cout << "Finished filling the decay map" << std::endl;
    while(germanium_reader.Next()) {
        germanium_map[*germanium_time] = std::make_tuple(*germanium_energy, *germanium_spill, *germanium_bplast);
    }
    std::cout << "Finished filling the maps" << std::endl;
    // Now we process the three maps - first we correlate the implant and decay events

    // Read gated implant events
    while (gatedimplant_reader.Next()) {
        all_implants.emplace(*gatedimplant_time, std::make_tuple(*gatedimplant_x, *gatedimplant_y, *gatedimplant_spill, *gatedimplant_bplast, GATEDIMPLANT));
    }
    std::cout << "Finished filling the gated implant map" << std::endl;

    // Read implant events
    while (implant_reader.Next()) {
        all_implants.emplace(*implant_time, std::make_tuple(*implant_x, *implant_y, *implant_spill, *implant_bplast, IMPLANT));
    }

    // Read decay events
    while (decay_reader.Next()) {
        event_map.emplace(*decay_time, std::make_tuple(*decay_x, *decay_y, *decay_spill, *decay_bplast, DECAY));
    }


    auto impit = implant_map.begin();
    auto gatedimpit = gatedimplant_map.begin();
    auto decayit = decay_map.begin();
    auto germanit = germanium_map.begin();

    int64_t last_gatedimplant_time;
    int64_t last_implant_time;
    int64_t last_decay_time;
    double gatedimplant_pos_x;
    double gatedimplant_pos_y;
    double implant_pos_x;
    double implant_pos_y;
    bool shitplant = false;
    bool broken_decay = false;
    int vetoed_implants = 0;

    // Print some information
    std::cout << "Number of events in the event map: " << all_implants.size() << std::endl;
    std::cout << "Number of events in the implant map: " << good_implants.size() << std::endl;

    std::unordered_map<std::pair<int, int>, int64_t, pair_hash> gated_implant_positions;

    // Loop over the event map and preprocess it, remove gated implants that are in the same position as an implant
    for (auto it = all_implants.begin(); it != all_implants.end(); ++it) {
        auto [x, y, spill, bplast, type] = it->second;

        // Show the event progress
        if (it->first % 1000 == 0) {
            std::cout << "\rProcessing event " << it->first << " of " << all_implants.size() << std::flush;
        }

        // Store gated implants in the unordered_map
        if (type == GATEDIMPLANT) {
            last_gatedimplant_time = it->first;
            gated_implant_positions[{x, y}] = it->first;
            // Add to the good implants
            // good_implants.emplace(it->first, it->second);
        }

        // Veto on implants in the same position
        if (type == IMPLANT) {
            last_implant_time = it->first;
            implant_pos_x = x;
            implant_pos_y = y;
            if (last_implant_time == last_gatedimplant_time) {
                continue;
            }

            auto pos = std::make_pair(x, y);
            if (gated_implant_positions.find(pos) != gated_implant_positions.end()) {
                int64_t gated_time = gated_implant_positions[pos];
                int64_t time_diff = it->first - gated_time;
                if (time_diff < 150 * 1e9) {
                    // std::cout << "We found a vetoed implant event" << std::endl;
                    vetoed_implants++;
                    gated_implant_positions.erase(pos);
                    continue;
                }
            }
        }
    }

    // Add the remaining gated implants to the good implants
    for (const auto& [pos, time] : gated_implant_positions) {
        good_implants.emplace(time, all_implants.find(time)->second);
    }

    // Print some information
    std::cout << "\nNumber of vetoed implant events: " << vetoed_implants << std::endl;
    std::cout << "Number of good implants: " << good_implants.size() << std::endl;


        // if (type == DECAY && gatedimplant_pos_x == x && gatedimplant_pos_y == y){
        //     if(broken_decay){
        //         continue;
        //     }
        //     // if(shitplant) continue;
        //     // if ((implant_pos_x == x && implant_pos_y == y) || shitplant) continue;
        //     // if (spill == 1) continue;
        //     last_decay_time = it->first;
        //     int64_t time_diff = it->first - last_gatedimplant_time;
        //     std::cout << "We matched an event with time difference: " << time_diff << std::endl;
        //     aida_implant_veto_dt->Fill(time_diff);
        //     double decay_pos_x = x;
        //     double decay_pos_y = y;
        //     // Calculate the position difference
        //     double pos_diff_x = std::abs(gatedimplant_pos_x - decay_pos_x);
        //     double pos_diff_y = std::abs(gatedimplant_pos_y - decay_pos_y);
        //     double pos_diff = std::sqrt(std::pow(pos_diff_x, 2) + std::pow(pos_diff_y, 2));
        //     aida_implant_dt_vs_pos_x->Fill(time_diff, pos_diff_x);
        //     aida_implant_dt_vs_pos_y->Fill(time_diff, pos_diff_y);
        //     aida_implant_dt_vs_pos_diff->Fill(time_diff, pos_diff);
        // }

    // const long long time_window = 50 * 1e9; // 50 seconds in nanoseconds

    // for (auto it = event_map.begin(); it != event_map.end(); ++it) {
    //     auto [x, y, spill, bplast, type] = it->second;

    //     if (type == IMPLANT) {
    //         // Forward search
    //         auto decay_start = event_map.lower_bound(it->first);
    //         auto decay_end = event_map.upper_bound(it->first + time_window);

    //         for (auto decay_it = decay_start; decay_it != decay_end; ++decay_it) {
    //             auto [decay_x, decay_y, decay_spill, decay_bplast, decay_type] = decay_it->second;

    //             if (decay_type == DECAY) {
    //                 long long time_diff = decay_it->first - it->first;
    //                 aida_implant_decay_time->Fill(time_diff / 1e9);
    //                 std::cout << "Forward time difference: " << time_diff << " ns" << std::endl;
    //             }
    //         }

    //         // Backward search
    //         if (it != event_map.begin()) {
    //             auto decay_start = event_map.lower_bound(it->first - time_window);
    //             auto decay_end = it; // Ensure we don't include the implant event itself

    //             for (auto decay_it = decay_start; decay_it != decay_end; ++decay_it) {
    //                 auto [decay_x, decay_y, decay_spill, decay_bplast, decay_type] = decay_it->second;

    //                 if (decay_type == DECAY) {
    //                     long long time_diff = it->first - decay_it->first; // Corrected to ensure negative time difference
    //                     aida_implant_decay_time->Fill(time_diff / 1e9);
    //                     std::cout << "Backward time difference: " << time_diff << " ns" << std::endl;
    //                 }
    //             }
    //         }
    //     }
    // }


    // Calculate the running average events every 150s in the implant_map and gated_implant map

    // // loop over the implant events
    // for (const auto& implant_event : implant_map){
    //     int64_t implant_time = implant_event.first;
    //     double implant_x = std::get<0>(implant_event.second);
    //     double implant_y = std::get<1>(implant_event.second);
    //     int implant_spill = std::get<2>(implant_event.second);
    //     int implant_bp = std::get<3>(implant_event.second);
    //     if (implant_time > 1.714253777e+18) continue;
    //     if (implant_time < 1.714235795e+18) continue;
    //     // int64_t implant_aida_dt = decay_time - implant_time;
    //     // aida_implant_xy->Fill(implant_x, implant_y);
    //     // Calculate the running average
    //     // if(implant_x < 368 && implant_x > 262 && implant_y < 116 && implant_y > 26){
    //         aida_averageimplant_150s->Fill((implant_time-wr_experiment_start)/1e9);
    //     // }
    // }

    // // loop over the gated implant events
    // for (const auto& gatedimplant_event : gatedimplant_map){
    //     int64_t gatedimplant_time = gatedimplant_event.first;
    //     double gatedimplat_x = std::get<0>(gatedimplant_event.second);
    //     double gatedimplant_y = std::get<1>(gatedimplant_event.second);
    //     int gatedimplant_spill = std::get<2>(gatedimplant_event.second);
    //     if (gatedimplant_time > 1.714253777e+18) continue;
    //     if (gatedimplant_time < 1.714235795e+18) continue;
    //     // int64_t gatedimplant_aida_dt = decay_time - gatedimplant_time;
    //     // aida_implant_xy->Fill(gatedimplat_x, gatedimplant_y);
    //     // Calculate the running average
    //     // if(gatedimplat_x < 322 && gatedimplat_x > 278 && gatedimplant_y < 92 && gatedimplant_y > 56){
    //         aida_averagegatedimplant_150s->Fill((gatedimplant_time-wr_experiment_start)/1e9);
    //     // }
    // }

    // // loop gated implant events
    // for (const auto& gatedimplant_event : gatedimplant_map){
    //     int64_t gatedimplant_time = gatedimplant_event.first;
    //     double gatedimplat_x = std::get<0>(gatedimplant_event.second);
    //     double gatedimplant_y = std::get<1>(gatedimplant_event.second);
    //     int gatedimplant_spill = std::get<2>(gatedimplant_event.second);
    //     // int64_t gatedimplant_aida_dt = decay_time - gatedimplant_time;
    //     aida_implant_xy->Fill(gatedimplat_x, gatedimplant_y);
    // }
    // // // loop over germanium events
    // for (const auto& germanium_event : germanium_map){
    //     int64_t germanium_time = germanium_event.first;
    //     double energy = std::get<0>(germanium_event.second);
    //     int germanium_spill = std::get<1>(germanium_event.second);
    //     // int64_t germanium_aida_dt = decay_time - germanium_time;
    //     // check if the germanium event is within 10000 to 20000 ns of the decay event
    //     if (germanium_spill == 2){
    //         // Fill the histogram with the germanium energy
    //         germanium_decay_energy->Fill(energy);
    //         // germanium_aida_wr_dt->Fill(germanium_aida_dt);
    //     }
    // }


    // // Define a tunable parameter for pixel adjacency
    // const double b = 3.0; // Adjust this value as needed

    // std::map<std::pair<double, double>, std::vector<std::pair<int64_t, std::tuple<double, double, int, int>>>> grouped_decay_map;
    // for (const auto& decay_event : decay_map) {
    //     double decay_x = std::get<0>(decay_event.second);
    //     double decay_y = std::get<1>(decay_event.second);
    //     int decay_spill = std::get<2>(decay_event.second);
    //     if(decay_spill != 2) continue;
    //     grouped_decay_map[{decay_x, decay_y}].emplace_back(decay_event.first, decay_event.second);
    // }
    // std::cout << "Finished grouping decay events" << std::endl;

    // // Create a sorted map of implant times with positions as keys
    // std::map<int64_t, std::pair<double, double>> sorted_implant_times;
    // for (const auto& implant_event : implant_map) {
    //     sorted_implant_times[implant_event.first] = {std::get<0>(implant_event.second), std::get<1>(implant_event.second)};
    // }

    // // Group of implants by position
    // std::map<std::pair<double, double>, std::vector<std::pair<int64_t, std::tuple<double, double, int, int>>> > grouped_implant_map;
    // for (const auto& implant_event : gatedimplant_map) {
    //     double implant_x = std::get<0>(implant_event.second);
    //     double implant_y = std::get<1>(implant_event.second);
    //     grouped_implant_map[{implant_x, implant_y}].emplace_back(implant_event.first, implant_event.second);
    // }
    // std::cout << "Finished grouping implant events" << std::endl;

    // // Iterate over implant events and match with grouped decay events
    // int spinner = 0;
    // for (const auto& implant_event : gatedimplant_map) {
    //     if (++spinner % 1000 == 0) {
    //         std::cout << "\rProcessing implant event " << spinner << " of " << gatedimplant_map.size() << std::flush;
    //     }
    //     int64_t implant_time = implant_event.first;
    //     std::tuple<double, double, int, int> implant = implant_event.second;
    //     double implant_x = std::get<0>(implant);
    //     double implant_y = std::get<1>(implant);
    //     int implant_spill = std::get<2>(implant);
    //     int implant_bp = std::get<3>(implant);
    //     // if (implant_spill == 2) continue;

    //     auto it = grouped_decay_map.find({implant_x, implant_y});
    //     if (it != grouped_decay_map.end()) {
    //         for (const auto& decay_event : it->second) {
    //             int64_t decay_time = decay_event.first;
    //             std::tuple<double, double, int, int> decay = decay_event.second;
    //             int decay_spill = std::get<2>(decay);
    //             int decay_bp = std::get<3>(decay);
    //             if (decay_spill != 2) continue;

    //             // Check if the decay is within 400 us after another implant event using binary search
    //             auto lower_bound = sorted_implant_times.lower_bound(decay_time - 400000);
    //             bool within_400us_of_other_implant = false;
    //             for (auto it = lower_bound; it != sorted_implant_times.end() && it->first <= decay_time; ++it) {
    //                 if (it->first != implant_time) {
    //                     within_400us_of_other_implant = true;
    //                     break;
    //                 }
    //             }
    //             if (within_400us_of_other_implant) continue;

    //             int64_t implant_decay_dt = decay_time - implant_time;
    //             if (implant_decay_dt > half_life_ns || implant_decay_dt < -half_life_ns) continue;

    //             // Check if the decay is interrupted by an implant at the same position up to 5 times the lifetime using binary search
    //             auto lower_bound_interrupt = sorted_implant_times.lower_bound(decay_time - half_life_ns);
    //             auto upper_bound_interrupt = sorted_implant_times.upper_bound(decay_time + half_life_ns);
    //             bool interrupted_by_implant = false;
    //             for (auto it = lower_bound_interrupt; it != upper_bound_interrupt; ++it) {
    //                 if (it->first != implant_time) {
    //                     double interrupt_x = it->second.first;
    //                     double interrupt_y = it->second.second;
    //                     if (interrupt_x == implant_x && interrupt_y == implant_y) {
    //                         interrupted_by_implant = true;
    //                         break;
    //                     }
    //                 }
    //             }
    //             if (interrupted_by_implant) continue;

    //             aida_implant_decay_time->Fill(implant_decay_dt / 1e9);
    //             // aida_implant_xy->Fill(implant_x, implant_y);
    //             aida_decay_xy->Fill(implant_x, implant_y);
    //             aida_wr_times->Fill((decay_time - wr_experiment_start) / 1e9);
    //         }
    //     }
    // }

    std::cout << "Finished processing the data" << std::endl;

    aida_gatedimplant_before_decay_counter->Write();
    aida_implant_before_decay_counter->Write();
    germanium_aida_wr_dt->Write();
    germanium_energy_hist->Write();
    aida_implant_xy->Write();
    aida_implant_decay_time->Write();
    aida_wr_times->Write();
    germanium_decay_energy->Write();
    aida_decay_xy->Write();
    aida_averageimplant_150s->Write();
    aida_averagegatedimplant_150s->Write();
    aida_implant_veto_dt->Write();
    aida_implant_dt_vs_pos_x->Write();
    aida_implant_dt_vs_pos_y->Write();
    aida_implant_dt_vs_pos_diff->Write();

    std::cout << "Finished writing the histograms" << std::endl;

    // Close the file
    delete file;
    delete outputFile;

    std::cout << "Finished closing the files" << std::endl;

}