#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>


// Tree reader and analyser for implant decay gamma analysis

void decaygamma(){
    // Open the file
    TFile *file = new TFile("output.root");
    if (!file) {
        std::cerr << "Error: Could not open output file " << std::endl;
        return;
    }

    // Open the output file
    TFile* outputFile = new TFile("out2.root", "RECREATE");
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << std::endl;
        return;
    }

    // Experiment information
    uint64_t wr_experiment_start = 1.71420318e+18;
    uint64_t wr_experiment_end = 1.71420372e+18;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 1; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    // Get the three trees
    TTree* implant_tree = (TTree*)file->Get("aida_implant_tree");
    TTree* decay_tree = (TTree*)file->Get("aida_decay_tree");
    TTree* germanium_tree = (TTree*)file->Get("germanium_tree");

    // Set tree readers

    TTreeReader implant_reader(implant_tree);
    TTreeReader decay_reader(decay_tree);
    TTreeReader germanium_reader(germanium_tree);

    TTreeReaderValue<Long64_t> implant_time(implant_reader, "implant.time");
    TTreeReaderValue<Int_t> implant_x(implant_reader, "implant.x");
    TTreeReaderValue<Int_t> implant_y(implant_reader, "implant.y");

    TTreeReaderValue<Long64_t> decay_time(decay_reader, "decay.time");
    TTreeReaderValue<Int_t> decay_x(decay_reader, "decay.x");
    TTreeReaderValue<Int_t> decay_y(decay_reader, "decay.y");
    TTreeReaderValue<std::vector<double>> decay_gammas(decay_reader, "decay.gammas");

    TTreeReaderValue<Long64_t> germanium_time(germanium_reader, "germanium.time");
    TTreeReaderValue<Double_t> germanium_energy(germanium_reader, "germanium.energy");

    // Histograms
    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 4e2, -1e4, 1e5);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);
    TH1F* germanium_decay_energy = new TH1F("germanium_decay_energy", "Germanium Decay Energy", 1.5e3, 0, 1.5e3);
    TH1F* germanium_aida_wr_dt = new TH1F("germanium_aida_wr_dt", "Germanium AIDA WR Time Difference", 1e3, -1e4, 1e5);


    // Make new maps for processing the data

    std::map<int64_t, std::pair<int, int>> aida_implant_map;
    std::map<int64_t, std::pair<std::pair<int, int>, std::vector<double>>> aida_decay_map;
    std::map<int64_t, double> germanium_map;

    // Loop over the implant and decay trees and fill the maps

    while (implant_reader.Next()) {
        aida_implant_map[*implant_time] = std::make_pair(*implant_x, *implant_y);
    }
    while(decay_reader.Next()) {
        aida_decay_map[*decay_time] = std::make_pair(std::make_pair(*decay_x, *decay_y), *decay_gammas);
    }
    while(germanium_reader.Next()) {
        germanium_map[*germanium_time] = *germanium_energy;
    }

    // Now we process the three maps - first we correlate the implant and decay events

    auto impit = aida_implant_map.begin();
    auto decayit = aida_decay_map.begin();
    auto germanit = germanium_map.begin();


    for (const auto& decay_event : aida_decay_map)
    {
        int64_t decay_time = decay_event.first;
        const auto& decay_data = decay_event.second;
        const auto& gamma_spectrum = decay_data.second;

        for (double gamma : gamma_spectrum)
        {
            // Fill the gamma spectrum for this decay time
            // Replace this with your actual code to fill the gamma spectrum
            std::cout << "Decay time: " << decay_time << ", Gamma: " << gamma << std::endl;
            germanium_decay_energy->Fill(gamma);
        }
    }

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

    // if (!aida_decay_map.empty() && !germanium_map.empty())
    // {
    //     auto decayit = aida_decay_map.begin();
    //     auto germanit = germanium_map.begin();

    //     int64_t aida_decay_time = decayit->first;

    //     // aida_decay_time -= 20000;

    //     // Print the time of the decay event (optional)
    //     // std::cout << "Decay time: " << aida_decay_time << std::endl;

    //     // Get the first germanium event
    //     int64_t germanium_time = germanit->first;
    //     int64_t germanium_aida_dt = germanium_time - aida_decay_time;
    //     std::cout << "Time difference: " << germanium_aida_dt << std::endl;
    // }

    germanium_aida_wr_dt->Write();
    germanium_energy_hist->Write();
    aida_implant_xy->Write();
    aida_implant_decay_time->Write();
    aida_wr_times->Write();
    germanium_decay_energy->Write();
    aida_decay_xy->Write();


    // Close the file
    delete file;
    delete outputFile;


}