#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>


// Tree reader and analyser for implant decay gamma analysis

void decaygamma(){
    // Create a chain of files for each tree
    TChain *implant_chain = new TChain("aida_implant_tree");
    TChain *gatedimplant_chain = new TChain("aida_gatedimplant_tree");
    TChain *decay_chain = new TChain("aida_decay_tree");
    TChain *germanium_chain = new TChain("germanium_tree");

    // Add files to the chains
    for (int i = 1; i <= 10; i++) {
        implant_chain->Add(Form("results/162Eu_0025_%04d_aidaana_output.root", i));
        gatedimplant_chain->Add(Form("results/162Eu_0025_%04d_aidaana_output.root", i));
        decay_chain->Add(Form("results/162Eu_0025_%04d_aidaana_output.root", i));
        germanium_chain->Add(Form("results/162Eu_0025_%04d_aidaana_output.root", i));
    }

    // ...

    // Get the trees
    TTree* implant_tree = implant_chain;
    TTree* gatedimplant_tree = gatedimplant_chain;
    TTree* decay_tree = decay_chain;
    TTree* germanium_tree = germanium_chain;

    // Get the three trees
    // TTree* implant_tree = (TTree*)file->Get("aida_implant_tree");
    // TTree* decay_tree = (TTree*)file->Get("aida_decay_tree");
    // TTree* germanium_tree = (TTree*)file->Get("germanium_tree");

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
    TTreeReaderValue<Int_t> implant_x(implant_reader, "implant.x");
    TTreeReaderValue<Int_t> implant_y(implant_reader, "implant.y");
    TTreeReaderValue<Int_t> implant_spill(implant_reader, "implant.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> implant_bplast(implant_reader, "implant.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> gatedimplant_time(gatedimplant_reader, "gatedimplant.time");
    TTreeReaderValue<Int_t> gatedimplant_x(gatedimplant_reader, "gatedimplant.x");
    TTreeReaderValue<Int_t> gatedimplant_y(gatedimplant_reader, "gatedimplant.y");
    TTreeReaderValue<Int_t> gatedimplant_spill(gatedimplant_reader, "gatedimplant.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> gatedimplant_bplast(gatedimplant_reader, "gatedimplant.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> decay_time(decay_reader, "decay.time");
    TTreeReaderValue<Int_t> decay_x(decay_reader, "decay.x");
    TTreeReaderValue<Int_t> decay_y(decay_reader, "decay.y");
    TTreeReaderValue<Int_t> decay_spill(decay_reader, "decay.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> decay_bplast(decay_reader, "decay.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired

    TTreeReaderValue<ULong64_t> germanium_time(germanium_reader, "germanium.time");
    TTreeReaderValue<Double_t> germanium_energy(germanium_reader, "germanium.energy");
    TTreeReaderValue<Int_t> germanium_spill(germanium_reader, "germanium.sp"); // sp = 1 spill, sp = 2 no spill
    TTreeReaderValue<Int_t> germanium_bplast(germanium_reader, "germanium.bp"); // bp = 0 neither fired, bp = 1 only bp1 fired, bp = 2 only bp2 fired, bp = 3 both fired
    
    // Experiment information
    uint64_t wr_experiment_start = 1.71420318e+18;
    uint64_t wr_experiment_end = 1.71420372e+18;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 1; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    // Histograms
    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 4e2, -1e4, 1e5);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);
    TH1F* germanium_decay_energy = new TH1F("germanium_decay_energy", "Germanium Decay Energy", 1.5e3, 0, 1.5e3);
    TH1F* germanium_aida_wr_dt = new TH1F("germanium_aida_wr_dt", "Germanium AIDA WR Time Difference", 1e3, -1e4, 1e5);

    // Make new maps for processing the data

    std::map<int64_t, std::tuple<int, int, int, int>> implant_map;
    std::map<int64_t, std::tuple<int, int, int, int>> gatedimplant_map;
    std::map<int64_t, std::tuple<int, int, int, int>> decay_map;
    std::map<int64_t, std::tuple<double,int, int>> germanium_map;

    // Loop over the implant and decay trees and fill the maps

    while (implant_reader.Next()) {
        implant_map[*implant_time] = std::make_tuple(*implant_x, *implant_y, *implant_spill, *implant_bplast);
    }
    while(gatedimplant_reader.Next()) {
        gatedimplant_map[*gatedimplant_time] = std::make_tuple(*gatedimplant_x, *gatedimplant_y, *gatedimplant_spill, *gatedimplant_bplast);
    }
    while(decay_reader.Next()) {
        decay_map[*decay_time] = std::make_tuple(*decay_x, *decay_y, *decay_spill, *decay_bplast);
    }
    while(germanium_reader.Next()) {
        germanium_map[*germanium_time] = std::make_tuple(*germanium_energy, *germanium_spill, *germanium_bplast);
    }

    // Now we process the three maps - first we correlate the implant and decay events

    auto impit = implant_map.begin();

    // print the time differences between the 1st and second events in the implant-decay map and implant-germanium map and decay-germanium map

    // for (const auto& decay_event : decay_map)
    // {
    //     int64_t decay_time = decay_event.first;
    //     const auto& decay_data = decay_event.second;
    //     const auto& gamma_spectrum = decay_data.second;

    //     for (double gamma : gamma_spectrum)
    //     {
    //         // Fill the gamma spectrum for this decay time
    //         // Replace this with your actual code to fill the gamma spectrum
    //         std::cout << "Decay time: " << decay_time << ", Gamma: " << gamma << std::endl;
    //         germanium_decay_energy->Fill(gamma);
    //     }
    // }

    // while (decayit != decay_map.end())
    auto gatedimpit = gatedimplant_map.begin();
    auto decayit = decay_map.begin();
    auto germanit = germanium_map.begin();


    // print the time differences between the 1st and second events in the implant-decay map and implant-germanium map and decay-germanium map

    

    // for (const auto& decay_event : aida_decay_map)
    // {
    //     int64_t decay_time = decay_event.first;
    //     const auto& decay_data = decay_event.second;
    //     const auto& gamma_spectrum = decay_data.second;

    //     for (double gamma : gamma_spectrum)
    //     {
    //         // Fill the gamma spectrum for this decay time
    //         // Replace this with your actual code to fill the gamma spectrum
    //         std::cout << "Decay time: " << decay_time << ", Gamma: " << gamma << std::endl;
    //         germanium_decay_energy->Fill(gamma);
    //     }
    // }

    // while (decayit != aida_decay_map.end())
    // {
    //     int64_t aida_decay_time = decayit->first;

    //     // Move impit to the first implant that is at or before the current decay
    //     while (impit != aida_implant_map.end() && impit->first <= aida_decay_time)
    //     {
    //         ++impit;
    //     }

    //     // Move germanit to the first germanium event that is at or before the current decay
    //     // Ensure we don't skip any valid events by carefully moving germanit
    //     while (germanit != germanium_map.end() && germanit->first <= aida_decay_time)
    //     {
    //         ++germanit;
    //     }

    //     // Start from the current implant and go backwards to find a matching implant
    //     auto impit_back = impit;
    //     auto germanit_temp = germanit;  // Temporary iterator for checking germanium events

    //     // Find matching implant
    //     while (impit_back != aida_implant_map.begin())
    //     {
    //         --impit_back;
    //         if (impit_back->second.first == decayit->second.first && impit_back->second.second == decayit->second.second)
    //         {
    //             int64_t aida_implant_time = impit_back->first;
    //             int64_t aida_implant_decay_dt = (aida_decay_time - aida_implant_time) / 1e6; // Time in ms

    //             // Fill histograms for implant-decay relationship
    //             aida_implant_decay_time->Fill(aida_implant_decay_dt);
    //             aida_implant_xy->Fill(impit_back->second.first, impit_back->second.second);
    //             aida_decay_xy->Fill(decayit->second.first, decayit->second.second);
    //             aida_wr_times->Fill((aida_decay_time - wr_experiment_start) / 1e9);

    //             // Look for gamma events strictly within 1 µs after the decay
    //             // germanit_temp = germanit;  // Reset temp iterator

    //             while (germanit_temp != germanium_map.end() && germanit_temp->first <= aida_decay_time + 100) // 100 ns = 100 ns
    //             {
    //                 std::cout << "inside the germanium loop" << std::endl;
    //                 int64_t germanium_tempt = germanit_temp->first;
    //                 double energy = germanit_temp->second;

    //                 // Ensure the gamma ray event is strictly after the decay time but within 100 ns
    //                 if (germanium_tempt > aida_decay_time - 100 && germanium_tempt < aida_decay_time + 100)
    //                 {
    //                     std::cout << "Found a gamma ray event within 100 ns of decay" << std::endl;
    //                     germanium_decay_energy->Fill(energy); // Fill histogram with gamma energy
    //                     // germanium_tree->Fill(); // Uncomment if needed
    //                 }
    //                 ++germanit_temp; // Advance the temporary iterator
    //             }

    //             // Remove the matched implant from the implant map
    //             aida_implant_map.erase(impit_back);
    //             break;
    //         }
    //     }

    //     ++decayit;
    // }




    // Test the maps

    // while (decayit != aida_decay_map.end())
    // {
    //     int64_t aida_decay_time = decayit->first;

    //     // aida_decay_time -= 20000;

    //     // Print the time of the decay event (optional)
    //     // std::cout << "Decay time: " << aida_decay_time << std::endl;

    //     // Advance germanit to the first germanium event strictly after the decay time
    //     while (germanit != germanium_map.end())
    //     {
    //         int64_t germanium_time = germanit->first;
    //         int64_t germanium_aida_dt = germanium_time - aida_decay_time;
    //         std::cout << "Time difference: " << germanium_aida_dt << std::endl;
    //         ++germanit;
    //         break;
    //     }

    //     // // Create a temporary iterator to loop over the relevant germanium events for this decay
    //     // auto germanit_temp = germanit;

    //     // // Now we check events occurring strictly between decay time and decay time + 1 µs
    //     // while (germanit_temp != germanium_map.end()) // 1 µs = 1000 ns
    //     // {
    //     //     int64_t germanium_time = germanit_temp->first;

    //     //     germanium_aida_wr_dt->Fill(germanium_time - aida_decay_time);
    //     //     ++germanit_temp;  // Move the temporary iterator, not the main germanium iterator
    //     // }

    //     ++decayit;
    // }

    // if (!decay_map.empty() && !germanium_map.empty())
    // {
    //     //first event 
    //     auto decayit = decay_map.begin();
    //     auto germanit = germanium_map.begin();

    //     int64_t aida_decay_time = decayit->first;

    //     // Get the first germanium event
    //     int64_t germanium_time = germanit->first;
    //     int64_t germanium_aida_dt = germanium_time - aida_decay_time;
    //     std::cout << "Time decay: " << aida_decay_time << std::endl;
    //     std::cout << "Time germanium: " << germanium_time << std::endl;
    //     std::cout << "Time difference: " << germanium_aida_dt << std::endl;

    //     // Advance the iterators
    //     ++decayit;
    //     ++germanit;

    //     //second event
    //     aida_decay_time = decayit->first;
    //     germanium_time = germanit->first;
    //     germanium_aida_dt = germanium_time - aida_decay_time;

    //     std::cout << "Time decay: " << aida_decay_time << std::endl;
    //     std::cout << "Time germanium: " << germanium_time << std::endl;
    //     std::cout << "Time difference: " << germanium_aida_dt << std::endl;

    //     ++decayit;
    //     ++germanit;

    //     //third event
    //     aida_decay_time = decayit->first;
    //     germanium_time = germanit->first;
    //     germanium_aida_dt = germanium_time - aida_decay_time;

    //     std::cout << "Time decay: " << aida_decay_time << std::endl;
    //     std::cout << "Time germanium: " << germanium_time << std::endl;
    //     std::cout << "Time difference: " << germanium_aida_dt << std::endl;


        // Result from this check
        // 1st event
        // Time decay: 1714203270188445830
        // Time germanium: 1714203271420957841
        // Time difference: 1232512011
        // 2nd event
        // Time decay: 1714203270189027830
        // Time germanium: 1714203272195782234
        // Time difference: 2006754404
        // 3rd event
        // Time decay: 1714203270189065830
        // Time germanium: 1714203272209052627
        // Time difference: 2019986797

    // }

    // loop over the decay map and find the germanium events that are between 11000 to 17000 ns of the decay event

    // for (const auto& decay_event : decay_map){
    //     int64_t decay_time = decay_event.first;

    //     // loop over germanium events
    //     for (const auto& germanium_event : germanium_map){
    //         int64_t germanium_time = germanium_event.first;
    //         double energy = germanium_event.second;
    //         int64_t germanium_aida_dt = decay_time - germanium_time;
    //         // check if the germanium event is within 10000 to 20000 ns of the decay event
    //         if (germanium_aida_dt > 11000 && germanium_aida_dt < 17000){
    //             // Fill the histogram with the germanium energy
    //             germanium_decay_energy->Fill(energy);
    //             germanium_aida_wr_dt->Fill(germanium_aida_dt);
    //         }
    //     }
    // }


    // Loop over the decay map and then the gated implant map to find the events with matching positions
    while (decayit != decay_map.end()) {
        int64_t decay_time = decayit->first;
        std::tuple<int, int, int, int> decay = decayit->second;
        int decay_x = std::get<0>(decay);
        int decay_y = std::get<1>(decay);
        int decay_spill = std::get<2>(decay);
        int decay_bp = std::get<3>(decay);

        // Check if the decay event is offspill ie. sp = 2

        if (decay_spill == 2) {
            ++decayit;
            continue;
        }

        // Check if the first event in the gated implant map is more than 75s away from the current decay
        if (!gatedimplant_map.empty()) {
            auto first_gated_implant = gatedimplant_map.begin();
            int64_t first_gated_time = first_gated_implant->first;
            int64_t first_gated_decay_dt = (decay_time - first_gated_time) / 1e6; // Time in ms

            // If the difference is more than 75 s, erase the first event
            if (first_gated_decay_dt > 75000) {
                gatedimplant_map.erase(first_gated_implant);
                // Continue to the next decay event since we just erased an event from the gated implant map
                continue;
            }
        }

        // Move the gated implant iterator to the first event that is at or after the decay event
        while (gatedimpit != gatedimplant_map.end() && gatedimpit->first <= decay_time) {
            ++gatedimpit;
        }

        // Start from the current gated implant event and go backwards to find a matching event
        auto gatedimpit_back = gatedimpit;

        while (gatedimpit_back != gatedimplant_map.begin()) {
            --gatedimpit_back;
            std::tuple<int, int, int, int> gatedimplant = gatedimpit_back->second;
            int gatedimplant_x = std::get<0>(gatedimplant);
            int gatedimplant_y = std::get<1>(gatedimplant);
            int gatedimplant_spill = std::get<2>(gatedimplant);
            int gatedimplant_bp = std::get<3>(gatedimplant);
            if (gatedimplant_x == decay_x && gatedimplant_y == decay_y) {
                int64_t gatedimplant_time = gatedimpit_back->first;
                int64_t gatedimplant_decay_dt = (decay_time - gatedimplant_time) / 1e6; // Time in ms

                // // If the time between the decay and gated implant is more than 75 s, skip the decay event
                // if (gatedimplant_decay_dt > 75000) {
                //     break;
                // }

                // Fill the histogram with the time difference
                aida_implant_decay_time->Fill(gatedimplant_decay_dt);
                aida_implant_xy->Fill(gatedimplant_x, gatedimplant_y);
                aida_decay_xy->Fill(decay_x, decay_y);
                aida_wr_times->Fill((decay_time - wr_experiment_start) / 1e9);

                // Now here we loop over the germanium data to find prompt events within 11000 to 17000 ns of the decay event
                for (const auto& germanium_event : germanium_map) {
                    int64_t germanium_time = germanium_event.first;
                    std::tuple<double, int, int> germanium = germanium_event.second;
                    double energy = std::get<0>(germanium);
                    int germanium_spill = std::get<1>(germanium);
                    int germanium_bp = std::get<2>(germanium);
                    int64_t germanium_aida_dt = decay_time - germanium_time;

                    if (germanium_aida_dt > 11000 && germanium_aida_dt < 17000) {
                        germanium_decay_energy->Fill(energy);
                        germanium_aida_wr_dt->Fill(germanium_aida_dt);
                    }
                }

                // // Remove the matched event from the gated implant map
                // gatedimplant_map.erase(gatedimpit_back);
                break;
            }
        }

        ++decayit;
    }


    germanium_aida_wr_dt->Write();
    germanium_energy_hist->Write();
    aida_implant_xy->Write();
    aida_implant_decay_time->Write();
    aida_wr_times->Write();
    germanium_decay_energy->Write();
    aida_decay_xy->Write();


    // Close the file
    delete implant_chain;
    delete gatedimplant_chain;
    delete decay_chain;
    delete germanium_chain;
    delete outputFile;


}