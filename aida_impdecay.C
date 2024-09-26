#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

void aida_impdecay(/*const char* filename*/) {
    // Open the file
    TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/cluster/trees/special/162Eu_new_0025_0001_aidaana.root");
    if (!file) {
        std::cerr << "Error: Could not open file " << std::endl;
        return;
    }

    // Get the existing tree
    TTree* old_tree = dynamic_cast<TTree*>(file->Get("evt"));
    if (!old_tree) {
        std::cerr << "Error: Could not find tree evt in file " << std::endl;
        return;
    }

    // Create a tree reader
    TTreeReader reader(old_tree);

    // Create tree reader values for the branches you want to read
    TTreeReaderValue<bool> spill(reader, "EventHeader.fSpillFlag");
    TTreeReaderArray<int64_t> implant_time(reader, "AidaImplantHits.Time");
    TTreeReaderArray<Int_t> implant_dssd(reader, "AidaImplantHits.DSSD");
    TTreeReaderArray<Bool_t> implant_stopped(reader, "AidaImplantHits.Stopped");
    TTreeReaderArray<Double_t> implant_x(reader, "AidaImplantHits.StripX");
    TTreeReaderArray<Double_t> implant_y(reader, "AidaImplantHits.StripY");

    TTreeReaderArray<int64_t> decay_time(reader, "AidaDecayHits.Time");
    TTreeReaderArray<Int_t> decay_dssd(reader, "AidaDecayHits.DSSD");
    TTreeReaderArray<int64_t> decay_time_x(reader, "AidaDecayHits.TimeX");
    TTreeReaderArray<int64_t> decay_time_y(reader, "AidaDecayHits.TimeY");
    TTreeReaderArray<Double_t> decay_energy_x(reader, "AidaDecayHits.EnergyX");
    TTreeReaderArray<Double_t> decay_energy_y(reader, "AidaDecayHits.EnergyY");
    TTreeReaderArray<Double_t> decay_x(reader, "AidaDecayHits.StripX");
    TTreeReaderArray<Double_t> decay_y(reader, "AidaDecayHits.StripY");

    TTreeReaderArray<uint64_t> germanium_time(reader, "GermaniumCalData.fwr_t");
    TTreeReaderArray<uint> germanium_det(reader, "GermaniumCalData.fdetector_id");
    TTreeReaderArray<uint> germanium_cry(reader, "GermaniumCalData.fcrystal_id");
    TTreeReaderArray<Double_t> germanium_energy(reader, "GermaniumCalData.fchannel_energy");

    TTreeReaderArray<Float_t> frs_x2(reader, "FrsHitData.fID_x2");
    TTreeReaderArray<Float_t> frs_z(reader, "FrsHitData.fID_z");
    TTreeReaderArray<Float_t> frs_z2(reader, "FrsHitData.fID_z2");
    TTreeReaderArray<Float_t> frs_aoq(reader, "FrsHitData.fID_AoQ_corr");
    TTreeReaderArray<uint64_t> frs_time(reader, "FrsHitData.fwr_t");

    uint64_t wr_experiment_start = 1.71420318e+18;
    uint64_t wr_experiment_end = 1.71420372e+18;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 1; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    // Load broken strips

    std::ifstream aida_strips_file("/u/jbormans/S100/analysis/aidatigerfish/AIDA_strips.txt");
    
    std::vector<int> broken_xstrips;
    std::vector<int> broken_ystrips;
    int dssd_number;
    std::string xy;
    int strip_number;
    int threshold;

    std::string line;

    while(std::getline(aida_strips_file, line))
    {
        if(line[0] == '#') continue;

        std::istringstream iss(line);
        iss >> dssd_number >> xy >> strip_number >> threshold;
        
        // If the threshold is -1, add the strip to the list of strips to skip
        if (threshold == -1) {
            if (xy == "X") {
                broken_xstrips.push_back(strip_number);
            } else if (xy == "Y") {
                broken_ystrips.push_back(strip_number);
            }
        }
    }

    // Load TCutG .root file

    TFile *cut_file = new TFile("/u/jbormans/S100/analysis/aidatigerfish/X2_Z1_65.root");
    TCutG *cutg = (TCutG*)cut_file->Get("CUTG");

    TFile *cut_file1 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/166Tb_Z_AoQ.root");
    TCutG *cutg1 = (TCutG*)cut_file1->Get("CUTG");

    TFile *cut_file2 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/Z63_X2.root");
    TCutG *cutg2 = (TCutG*)cut_file2->Get("CUTG");

    TFile *cut_file3 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/162Eu_AoQ.root");

    TCutG *cut163Eu = (TCutG*)cut_file3->Get("CUTG");

    // Open the output file
    TFile* outputFile = new TFile("output.root", "RECREATE");
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << std::endl;
        return;
    }

    // Create a new tree with the same structure as the old tree
    TTree* implant_tree = new TTree("aida_implant_tree", "New AIDA Analysis Tree");

    TTree* decay_tree = new TTree("aida_decay_tree", "New AIDA Analysis Tree");

    TTree* germanium_tree = new TTree("germanium_tree", "New AIDA Analysis Tree");

    // Make maps for the data

    std::map<int64_t, std::pair<int, int>> aida_implant_map;
    std::map<int64_t, std::pair<int, int>> aida_decay_map;
    std::map<int64_t, double> germanium_map;

    // Define the data structures
    struct implant_data
    {
        Long64_t time;
        int x;
        int y;
    } aida_implant_data;

    struct decay_data
    {
        Long64_t time;
        int x;
        int y;
    } aida_decay_data;

    struct germanium_data
    {
        Long64_t time;
        double energy;
    } germanium_data;

    // Create the branches
    implant_tree->Branch("implant", &aida_implant_data, "time/L:x/I:y/I");
    decay_tree->Branch("decay", &aida_decay_data, "time/L:x/I:y/I");
    germanium_tree->Branch("germanium", &germanium_data, "time/L:energy/D");

    // Make histogram for drawing germanium data

    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 4e2, -1e4, 1e5);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);

    const char spinner[] = {'-', '\\', '|', '/'};
    int totalEntries = reader.GetEntries(true);

    // Loop over all entries in the old tree
    while (reader.Next()) {
        // Read the data from the old tree
        // Show the progress of the loop
        if (reader.GetCurrentEntry() % 1000 == 0) {
            int progress = (reader.GetCurrentEntry() * 100) / totalEntries;
            char spin = spinner[reader.GetCurrentEntry() / 1000 % 4];
            std::cout << "\rProcessing the tree " << reader.GetCurrentEntry() << " (" << progress << "%) " << spin << std::flush;
        }
        // sizes
        int germaniumhits = germanium_time.GetSize();
        int aidadecayhits = decay_time.GetSize();
        int aidaimphits = implant_time.GetSize();
        int frshits = frs_time.GetSize();

        // Implants in coincidence with FRS
        if (frshits > 0 && aidaimphits > 0) {
            for (int i = 0; i < frshits; i++) {
                if (cutg->IsInside(frs_z[i], frs_x2[i]) && cutg1->IsInside(frs_aoq[i], frs_z[i])) {
                    bool filltree = false;
                    for (int j = 0; j < aidaimphits; j++) {
                        if (implant_dssd[j] == 1 && implant_stopped[j] == true) {
                            aida_implant_data.time = implant_time[j];
                            aida_implant_data.x = implant_x[j];
                            aida_implant_data.y = implant_y[j];
                            // aida_implant_xy->Fill(implant_x[j], implant_y[j]);
                            // Add to the map
                            aida_implant_map[implant_time[j]] = std::make_pair(implant_x[j], implant_y[j]);
                            implant_tree->Fill();
                        }
                    }
                }
            }
        }


        // Decays in coincidence with Germanium
        if (aidadecayhits > 0) {
            for (int i = 0; i < aidadecayhits; i++) {
                
                // DSSD 1 and time calibrated events
                if(decay_dssd[i] != 1 && TMath::Abs(decay_time_x[i] - decay_time_y[i]) > 1e3) continue;
                // Removing broken strips
                if (std::find(broken_xstrips.begin(), broken_xstrips.end(), decay_x[i]) != broken_xstrips.end() || std::find(broken_ystrips.begin(), broken_ystrips.end(), decay_y[i]) != broken_ystrips.end()) continue;
                // FB low dE noise cut
                if (TMath::Abs(decay_energy_x[i] - decay_energy_y[i]) > 200) continue;
                // FB low E noise cut
                if (decay_energy_x[i] < 200 && decay_energy_y[i] < 200) continue;
                // Spill off decay
                if(*spill == true) continue;

                aida_decay_data.time = decay_time[i];
                aida_decay_data.x = decay_x[i];
                aida_decay_data.y = decay_y[i];
                // aida_decay_xy->Fill(decay_x[i], decay_y[i]);
                // Add to the map
                aida_decay_map[decay_time[i]] = std::make_pair(decay_x[i], decay_y[i]);
                decay_tree->Fill();
  
            }
        }

        if(germaniumhits > 0){
            for (int i = 0; i < germaniumhits; i++) {
                if (germanium_det[i] == 1 /*&& germanium_det[i] <= 12 && germanium_cry[i] >= 0 && germanium_cry[i] <= 2 && germanium_energy[i] >= 0*/) {
                    germanium_data.time = germanium_time[i];
                    double energy = germanium_energy[i];
                    germanium_energy_hist->Fill(energy);
                    germanium_data.energy = energy;
                    // Fill the new tree with the data
                    germanium_tree->Fill();
                    // Add to the map
                    germanium_map[germanium_time[i]] = energy;
                }
            }
        } 
    }

    // Now we process the three trees - first we correlate the implant and decay events

    // Create a new tree with the good decays

    TTree* good_decay_tree = new TTree("good_decay_tree", "Good Decays");

    // Define the data structure

    struct good_decay_data
    {
        Long64_t time;
        int x;
        int y;
    } good_decay;

    // Create the branches

    good_decay_tree->Branch("good_decay", &good_decay, "time/L:x/I:y/I");

    // Create readers for the implant and decay trees

    TTreeReader implant_reader(implant_tree);
    TTreeReader decay_reader(decay_tree);

    // Loop over the maps

    auto impit = aida_implant_map.begin();
    auto decayit = aida_decay_map.begin();
    auto germanit = germanium_map.begin();

    while (decayit != aida_decay_map.end())
    {
        // Show the progress of the loop
        if (std::distance(aida_decay_map.begin(), decayit) % 1000 == 0) {
            int progress = (std::distance(aida_decay_map.begin(), decayit) * 100) / totalEntries;
            char spin = spinner[std::distance(aida_decay_map.begin(), decayit) / 1000 % 4];
            std::cout << "\rProcessing the decay map " << std::distance(aida_decay_map.begin(), decayit) << " (" << progress << "%) " << spin << std::flush;
        }
        int64_t aida_decay_time = decayit->second.first;

        // Move impit to the first implant that is at or after the current decay
        while (impit != aida_implant_map.end() && impit->second.first <= aida_decay_time)
        {
            ++impit;
        }

        // Start from the current implant and go backwards until we find a matching implant
        auto impit_back = impit;

        while (impit_back != aida_implant_map.begin())
        {
            --impit_back;
            std::cout << "Checking implant " << impit_back->second.first << " " << impit_back->second.second << std::endl;
            if (impit_back->second.first == decayit->second.first && impit_back->second.second == decayit->second.second)
            {

                std::cout << "Found a matching implant and decay event" << std::endl;
                int64_t aida_implant_time = impit_back->second.first;
                int aida_implant_decay_dt = (aida_decay_time - aida_implant_time)/1e6; // time in ms

                // If the decay is within a 400 us time window to the implant, skip this iteration
                if (aida_implant_decay_dt < 0.4) {
                    break;
                }

                aida_implant_decay_time->Fill(aida_implant_decay_dt);
                aida_implant_xy->Fill(impit_back->second.first, impit_back->second.second);
                aida_decay_xy->Fill(decayit->second.first, decayit->second.second);

                aida_wr_times->Fill((aida_decay_time - wr_experiment_start)/1e9);
                // Iterate over the germanit tree and fill the germanium spectrum when a matching decay and implant is found

                // Remove the matched implant from the implant tree
                aida_implant_map.erase(impit_back);
                break;
            }
        }

        ++decayit;
    }

    // Write the new tree to the file
    aida_implant_xy->Write();
    aida_implant_decay_time->Write();
    aida_wr_times->Write();
    germanium_energy_hist->Write();
    aida_decay_xy->Write();
    implant_tree->Write();
    decay_tree->Write();
    germanium_tree->Write();

    // Close the file
    delete file;
    delete outputFile;
}