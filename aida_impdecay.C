#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>

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
    TTreeReaderArray<int64_t> implants_time(reader, "AidaImplantHits.Time");
    TTreeReaderArray<Int_t> implants_dssd(reader, "AidaImplantHits.DSSD");
    TTreeReaderArray<Bool_t> implants_stopped(reader, "AidaImplantHits.Stopped");
    TTreeReaderArray<Double_t> implants_x(reader, "AidaImplantHits.StripX");
    TTreeReaderArray<Double_t> implants_y(reader, "AidaImplantHits.StripY");

    TTreeReaderArray<int64_t> decays_time(reader, "AidaDecayHits.Time");
    TTreeReaderArray<Int_t> decays_dssd(reader, "AidaDecayHits.DSSD");
    TTreeReaderArray<int64_t> decay_times_x(reader, "AidaDecayHits.TimeX");
    TTreeReaderArray<int64_t> decay_times_y(reader, "AidaDecayHits.TimeY");
    TTreeReaderArray<Double_t> decays_energy_x(reader, "AidaDecayHits.EnergyX");
    TTreeReaderArray<Double_t> decays_energy_y(reader, "AidaDecayHits.EnergyY");
    TTreeReaderArray<Double_t> decays_x(reader, "AidaDecayHits.StripX");
    TTreeReaderArray<Double_t> decays_y(reader, "AidaDecayHits.StripY");

    TTreeReaderArray<uint64_t> germanium_time(reader, "GermaniumCalData.fwr_t");
    TTreeReaderArray<uint> germanium_det(reader, "GermaniumCalData.fdetector_id");
    TTreeReaderArray<uint> germanium_cry(reader, "GermaniumCalData.fcrystal_id");
    TTreeReaderArray<Double_t> germanium_energy(reader, "GermaniumCalData.fchannel_energy");

    TTreeReaderArray<Float_t> frs_x2(reader, "FrsHitData.fID_x2");
    TTreeReaderArray<Float_t> frs_z(reader, "FrsHitData.fID_z");
    TTreeReaderArray<Float_t> frs_z2(reader, "FrsHitData.fID_z2");
    TTreeReaderArray<Float_t> frs_aoq(reader, "FrsHitData.fID_AoQ_corr");
    TTreeReaderArray<uint64_t> frs_time(reader, "FrsHitData.fwr_t");

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
    TTree* new_tree = new TTree("aida_ana_tree", "New AIDA Analysis Tree");

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
    new_tree->Branch("implants", &aida_implant_data, "time/L:x/I:y/I");
    new_tree->Branch("decays", &aida_decay_data, "time/L:x/I:y/I");
    new_tree->Branch("germanium", &germanium_data, "time/L:energy/D");

    // Make histogram for drawing germanium data

    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);

    // Loop over all entries in the old tree
    while (reader.Next()) {
        // Read the data from the old tree
        // sizes
        int germaniumhits = germanium_time.GetSize();
        int aidadecayhits = decays_time.GetSize();
        int aidaimphits = implants_time.GetSize();
        int frshits = frs_time.GetSize();

        // Implants in coincidence with FRS
        if (frshits > 0 && aidaimphits > 0) {
            for (int i = 0; i < frshits; i++) {
                if (cutg->IsInside(frs_z[i], frs_x2[i]) && cutg1->IsInside(frs_aoq[i], frs_z[i])) {
                    bool filltree = false;
                    for (int j = 0; j < aidaimphits; j++) {
                        if (implants_dssd[j] == 1 && implants_stopped[j] == true) {
                            aida_implant_data.time = implants_time[j];
                            aida_implant_data.x = implants_x[j];
                            aida_implant_data.y = implants_y[j];
                            aida_implant_xy->Fill(implants_x[j], implants_y[j]);
                            filltree = true;
                        }
                    }
                    if (filltree) {
                        new_tree->Fill();
                    }
                }
            }
        }

        if (germaniumhits > 0) {
            germanium_data.time = germanium_time[0];
        }
        if (germaniumhits > 0) {
            for (int i = 0; i < germaniumhits; i++) {
                if (germanium_det[i] == 1 /*&& germanium_det[i] <= 12 && germanium_cry[i] >= 0 && germanium_cry[i] <= 2 && germanium_energy[i] >= 0*/) {
                    double energy = germanium_energy[i];
                    germanium_data.energy = energy;
                    germanium_energy_hist->Fill(energy);
                    // Fill the new tree with the data
                    new_tree->Fill();
                }
            }
        }
    }

    // Write the new tree to the file
    aida_implant_xy->Write();
    germanium_energy_hist->Write();
    new_tree->Write();

    // Close the file
    delete file;
    delete outputFile;
}