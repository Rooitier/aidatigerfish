#include <iostream>
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

void decaygamma(){

    // Load file
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_all_new.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_backg.root");
    // TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_all_new.root");
    TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/analysis/betaion/results/162Eu_doubles_e.root");

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
    uint64_t wr_experiment_end = 1.7143668e+18 ;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 1; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    // half life of 166Dy
    double half_life = 27.1; // seconds
    double total_time = 150.0; // seconds
    int bins_per_half_life = 10;
    int number_of_bins = (total_time/half_life)*bins_per_half_life;


    // Histograms
    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 2*number_of_bins, -total_time, total_time);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);
    TH1F* germanium_decay_energy = new TH1F("germanium_decay_energy", "Germanium Decay Energy", 1.5e3, 0, 1.5e3);
    TH1F* germanium_aida_wr_dt = new TH1F("germanium_aida_wr_dt", "Germanium AIDA WR Time Difference", 1e3, -1e5, 1e5);
    TH1F* aida_implant_before_decay_counter = new TH1F("aida_implant_before_decay_counter", "AIDA Implant Before Decay Counter", 10, 0, 10);
    TH1F* aida_gatedimplant_before_decay_counter = new TH1F("aida_gatedimplant_before_decay_counter", "AIDA Gated Implant Before Decay Counter", 1e3, 0, 1e3);
    TH2F* aida_posdiff_time = new TH2F("aida_posdiff_time", "AIDA Position Difference vs Time", 1e3, 0, 1e3, 1e3, -1e4, 1e5);

    // Make new maps for processing the data

    std::map<int64_t, std::tuple<double, double, int, int>> implant_map;
    std::map<int64_t, std::tuple<double, double, int, int>> gatedimplant_map;
    std::map<int64_t, std::tuple<double, double, int, int>> decay_map;
    std::map<int64_t, std::tuple<double,int, int>> germanium_map;

    // Loop over the implant and decay trees and fill the maps
    std::cout << "Filling the maps" << std::endl;
    while (implant_reader.Next()) {
        implant_map[*implant_time] = std::make_tuple(*implant_x, *implant_y, *implant_spill, *implant_bplast);
    }
    std::cout << "Finished filling the implant map" << std::endl;
    while(gatedimplant_reader.Next()) {
        gatedimplant_map[*gatedimplant_time] = std::make_tuple(*gatedimplant_x, *gatedimplant_y, *gatedimplant_spill, *gatedimplant_bplast);
    }
    std::cout << "Finished filling the gated implant map" << std::endl;
    while(decay_reader.Next()) {
        decay_map[*decay_time] = std::make_tuple(*decay_x, *decay_y, *decay_spill, *decay_bplast);
    }
    std::cout << "Finished filling the decay map" << std::endl;
    while(germanium_reader.Next()) {
        germanium_map[*germanium_time] = std::make_tuple(*germanium_energy, *germanium_spill, *germanium_bplast);
    }
    std::cout << "Finished filling the maps" << std::endl;
    // Now we process the three maps - first we correlate the implant and decay events

    auto impit = implant_map.begin();
    auto gatedimpit = gatedimplant_map.begin();
    auto decayit = decay_map.begin();
    auto germanit = germanium_map.begin();

    // loop gated implant events
    for (const auto& gatedimplant_event : gatedimplant_map){
        int64_t gatedimplant_time = gatedimplant_event.first;
        double gatedimplat_x = std::get<0>(gatedimplant_event.second);
        double gatedimplant_y = std::get<1>(gatedimplant_event.second);
        int gatedimplant_spill = std::get<2>(gatedimplant_event.second);
        // int64_t gatedimplant_aida_dt = decay_time - gatedimplant_time;
        aida_implant_xy->Fill(gatedimplat_x, gatedimplant_y);
    }
    // // loop over germanium events
    for (const auto& germanium_event : germanium_map){
        int64_t germanium_time = germanium_event.first;
        double energy = std::get<0>(germanium_event.second);
        int germanium_spill = std::get<1>(germanium_event.second);
        // int64_t germanium_aida_dt = decay_time - germanium_time;
        // check if the germanium event is within 10000 to 20000 ns of the decay event
        if (germanium_spill == 2){
            // Fill the histogram with the germanium energy
            germanium_decay_energy->Fill(energy);
            // germanium_aida_wr_dt->Fill(germanium_aida_dt);
        }
    }


    // Define a tunable parameter for pixel adjacency
    const double b = 3.0; // Adjust this value as needed

    // lifetime
    double lifetime = 27.1; // seconds


    std::map<std::pair<double, double>, std::vector<std::pair<int64_t, std::tuple<double, double, int, int>>>> grouped_decay_map;
    for (const auto& decay_event : decay_map) {
        double decay_x = std::get<0>(decay_event.second);
        double decay_y = std::get<1>(decay_event.second);
        int decay_spill = std::get<2>(decay_event.second);
        if(decay_spill != 2) continue;
        grouped_decay_map[{decay_x, decay_y}].emplace_back(decay_event.first, decay_event.second);
    }
    std::cout << "Finished grouping decay events" << std::endl;

    // Create a sorted list of implant times
    std::vector<int64_t> sorted_implant_times;
    for (const auto& implant_event : gatedimplant_map) {
        sorted_implant_times.push_back(implant_event.first);
    }
    std::sort(sorted_implant_times.begin(), sorted_implant_times.end());

    // Group of implants by position
    std::map<std::pair<double, double>, std::vector<std::pair<int64_t, std::tuple<double, double, int, int>>> > grouped_implant_map;
    for (const auto& implant_event : gatedimplant_map) {
        double implant_x = std::get<0>(implant_event.second);
        double implant_y = std::get<1>(implant_event.second);
        grouped_implant_map[{implant_x, implant_y}].emplace_back(implant_event.first, implant_event.second);
    }
    std::cout << "Finished grouping implant events" << std::endl;

    // Iterate over implant events and match with grouped decay events
    int spinner = 0;
    for (const auto& implant_event : gatedimplant_map) {
        if (++spinner % 1000 == 0) {
            std::cout << "\rProcessing implant event " << spinner << " of " << gatedimplant_map.size() << std::flush;
        }
        int64_t implant_time = implant_event.first;
        std::tuple<double, double, int, int> implant = implant_event.second;
        double implant_x = std::get<0>(implant);
        double implant_y = std::get<1>(implant);
        int implant_spill = std::get<2>(implant);
        int implant_bp = std::get<3>(implant);
        // if (implant_spill == 2) continue;

        auto it = grouped_decay_map.find({implant_x, implant_y});
        if (it != grouped_decay_map.end()) {
            for (const auto& decay_event : it->second) {
                int64_t decay_time = decay_event.first;
                std::tuple<double, double, int, int> decay = decay_event.second;
                int decay_spill = std::get<2>(decay);
                int decay_bp = std::get<3>(decay);
                if (decay_spill != 2) continue;

                // Check if the decay is within 400 us after another implant event using binary search
                auto lower_bound = std::lower_bound(sorted_implant_times.begin(), sorted_implant_times.end(), decay_time - 400000);
                bool within_400us_of_other_implant = false;
                for (auto it = lower_bound; it != sorted_implant_times.end() && *it <= decay_time; ++it) {
                    if (*it != implant_time) {
                        within_400us_of_other_implant = true;
                        break;
                    }
                }
                if (within_400us_of_other_implant) continue;

                int64_t implant_decay_dt = decay_time - implant_time;
                if (implant_decay_dt > 150e9 || implant_decay_dt < -150e9) continue;
                aida_implant_decay_time->Fill(implant_decay_dt / 1e9);
                // aida_implant_xy->Fill(implant_x, implant_y);
                aida_decay_xy->Fill(implant_x, implant_y);
                aida_wr_times->Fill((decay_time - wr_experiment_start) / 1e9);
            }
        }
    }

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

    std::cout << "Finished writing the histograms" << std::endl;

    // Close the file
    delete file;
    delete outputFile;

    std::cout << "Finished closing the files" << std::endl;

}