#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

void aida_impdecay(/*const char* input, const char* output*/) {
    // Open the file
    TFile* file = TFile::Open("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_0007_0001.root");
    // TFile* file = TFile::Open(filea);
    // if (!file) {
    //     std::cerr << "Error: Could not open file " << std::endl;
    //     return;
    // }

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
    TTreeReaderArray<Int_t> decay_cluster_size_x(reader, "AidaDecayHits.ClusterSizeX");
    TTreeReaderArray<Int_t> decay_cluster_size_y(reader, "AidaDecayHits.ClusterSizeY");

    // TTreeReaderArray<uint64_t> germanium_time(reader, "GermaniumAnlData.fwr_t");
    TTreeReaderArray<int64_t> germanium_abs_ev_time(reader, "GermaniumAnlData.fabsolute_event_time");
    TTreeReaderArray<uint> germanium_det(reader, "GermaniumAnlData.fdetector_id");
    TTreeReaderArray<uint> germanium_cry(reader, "GermaniumAnlData.fcrystal_id");
    TTreeReaderArray<Double_t> germanium_energy(reader, "GermaniumAnlData.fchannel_energy");

    TTreeReaderArray<Float_t> frs_x2(reader, "FrsHitData.fID_x2");
    TTreeReaderArray<Float_t> frs_z(reader, "FrsHitData.fID_z");
    TTreeReaderArray<Float_t> frs_z2(reader, "FrsHitData.fID_z2");
    TTreeReaderArray<Float_t> frs_aoq(reader, "FrsHitData.fID_AoQ_corr");
    TTreeReaderArray<uint64_t> frs_time(reader, "FrsHitData.fwr_t");


    TTreeReaderArray<ULong_t> bplast_time(reader, "bPlastTwinpeaksCalData.fwr_t");
    TTreeReaderArray<uint64_t> bplast_abs_ev_time(reader, "bPlastTwinpeaksCalData.fabsolute_event_time");
    TTreeReaderArray<ushort> bplast_id(reader, "bPlastTwinpeaksCalData.fdetector_id");

    uint64_t wr_experiment_start = 1.71420318e+18;
    uint64_t wr_experiment_end = 1.71420372e+18;
    int64_t duration_in_seconds = (wr_experiment_end - wr_experiment_start)/1e9;
    int64_t slices_every = 1; //s
    int64_t number_of_slices = duration_in_seconds/slices_every;

    int counter = 0;

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
                strip_number = strip_number - 1;
                broken_xstrips.push_back(strip_number);
            } else if (xy == "Y") {
                strip_number = strip_number - 1;
                broken_ystrips.push_back(strip_number);
            }
        }
    }

    // Print out broken strips

    for(auto x : broken_xstrips) {
        std::cout << "Broken X strip: " << x << std::endl;
    }
    for(auto y : broken_ystrips) {
        std::cout << "Broken Y strip: " << y << std::endl;
    }

    // Load TCutG .root file

    TFile *Eucut_file = new TFile("/u/jbormans/S100/analysis/aidatigerfish/160Eu_1609.root");

    TCutG *Eu_Z_AoQ = (TCutG*)Eucut_file->Get("cut_Z_AoQ");

    TCutG *Eu_Z_Z2 = (TCutG*)Eucut_file->Get("cut_Z_Z2");

    TFile *Tbcut_file = new TFile("/u/jbormans/S100/analysis/aidatigerfish/X2_Z1_65.root");

    TCutG *Tb_x2_Z = (TCutG*)Tbcut_file->Get("CUTG");

    TFile *Tbcut_file1 = new TFile("/u/jbormans/S100/analysis/aidatigerfish/166Tb_Z_AoQ.root");

    TCutG *Tb_Z_AoQ = (TCutG*)Tbcut_file1->Get("CUTG");


    // Open the output file
    TFile* outputFile = new TFile("output.root", "RECREATE");
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << std::endl;
        return;
    }

    // Create a new tree with the same structure as the old tree
    TTree* implant_tree = new TTree("aida_implant_tree", "New AIDA Analysis Tree");

    TTree* gatedimplant_tree = new TTree("aida_gatedimplant_tree", "New AIDA Analysis Tree");

    TTree* decay_tree = new TTree("aida_decay_tree", "New AIDA Analysis Tree");

    TTree* germanium_tree = new TTree("germanium_tree", "New AIDA Analysis Tree");


    // Define the data structures
    struct implant_data
    {
        uint64_t time;
        int x;
        int y;
        int sp;
        int bp;
    } aida_implant_data;
    
    struct decay_data
    {
        uint64_t time;
        int x;
        int y;
        int sp;
        int bp;
    } aida_decay_data;

    struct germanium_data
    {
        uint64_t time;
        double energy;
        int sp;
        int bp;
    } germanium_data;

    // Create the branches
    implant_tree->Branch("implant", &aida_implant_data, "time/l:x/I:y/I:sp/I:bp/I");
    gatedimplant_tree->Branch("gatedimplant", &aida_implant_data, "time/l:x/I:y/I:sp/I:bp/I");
    decay_tree->Branch("decay", &aida_decay_data, "time/l:x/I:y/I:sp/I:bp/I");
    germanium_tree->Branch("germanium", &germanium_data, "time/l:energy/D:sp/I:bp/I");

    // Make histogram for drawing germanium data

    TH1F* germanium_energy_hist = new TH1F("germanium_energy_hist", "Germanium Energy", 1.5e3, 0, 1.5e3);
    TH2F* aida_implant_xy = new TH2F("aida_implant_xy", "AIDA Implant XY", 384, 0, 384, 128, 0, 128);
    TH2F* aida_decay_xy = new TH2F("aida_decay_xy", "AIDA Decay XY", 384, 0, 384, 128, 0, 128);
    TH1F* aida_implant_decay_time = new TH1F("aida_implant_decay_time", "AIDA Implant Decay Time", 4e2, -1e4, 1e5);
    TH1F* aida_wr_times = new TH1F("aida_wr_times", "AIDA WR Times", number_of_slices, 0, duration_in_seconds);
    TH1F* germanium_decay_energy = new TH1F("germanium_decay_energy", "Germanium Decay Energy", 1.5e3, 0, 1.5e3);

    const char spinner[] = {'-', '\\', '|', '/'};
    int totalEntries = reader.GetEntries(true);

    // Loop over all entries in the old tree
    while (reader.Next()) {
        // Read the data from the old tree

        // Get the spill flag
        // bool spill_flag = *spill;


        // sizes
        int germaniumhits = germanium_abs_ev_time.GetSize();
        int aidadecayhits = decay_time.GetSize();
        int aidaimphits = implant_time.GetSize();
        int frshits = frs_time.GetSize();
        int bplasthits = bplast_abs_ev_time.GetSize();
        
        
        int spflag = 0;
        int decflag = 0;
        int bpflag = 0;
        int bp1flag = 0;
        int bp2flag = 0;

/*         cout << "# of FRS hits:  " << frshits << endl;
         cout << "# of implant hits:  " << aidaimphits << endl;
         cout << "# of decay hits:  " << aidadecayhits << endl;
         cout << "# of gamma hits:  " << germaniumhits << endl;
         if (bplasthits > 0) cout << "# of bplast hits:  " << bplasthits << endl; */

        if(*spill == true) spflag = 1;
        if(*spill == false) spflag = 2;
        
        
        
        for (int j = 0; j < bplasthits; j++) {

//            cout << j << "  " << bplast_id[j] << endl;
            if(bplast_id[j] < 64) bp1flag = 1;
            if(bplast_id[j] > 63 && bplast_id[j] < 128) bp2flag = 1;

        }
    
    if (bp1flag == 1 && bp2flag == 0) bpflag = 1;
    if (bp1flag == 0 && bp2flag == 1) bpflag = 2;
    if (bp1flag == 1 && bp2flag == 1) bpflag = 3;
        
//        cout << bp1flag << "  " << bp2flag << "  " << bpflag << endl;

        for (int j = 0; j < aidaimphits; j++) {
            if (implant_dssd[j] == 1 && implant_stopped[j] == true) {
                
                aida_implant_data.time = implant_time[j];
                aida_implant_data.x = implant_x[j];
                aida_implant_data.y = implant_y[j];
                aida_implant_data.sp = spflag;
                aida_implant_data.bp = bpflag;

                implant_tree->Fill();

            }
        }
        
// Implants in coincidence with FRS
        if (frshits == 1 && aidaimphits == 1) {
            for (int i = 0; i < frshits; i++) {
                if (/*(Eu_Z_Z2->IsInside(frs_z2[i], frs_z[i]) && Eu_Z_AoQ->IsInside(frs_aoq[i], frs_z[i])) || */ (Tb_x2_Z->IsInside(frs_z[i], frs_x2[i]) && Tb_Z_AoQ->IsInside(frs_aoq[i], frs_z[i]))) {
                    std::cout << "Implant in coincidence with FRS" << std::endl;
                    for (int j = 0; j < aidaimphits; j++) {
                        if (implant_dssd[j] == 1 && implant_stopped[j] == true) {
                            
                            aida_implant_data.time = implant_time[j];
                            aida_implant_data.x = implant_x[j];
                            aida_implant_data.y = implant_y[j];
                            aida_implant_data.sp = spflag;
                            aida_implant_data.bp = bpflag;

//                            imptime = implant_time[j];
//                            impx = implant_x[j];
//                            impy = implant_y[j];

//                            cout << imptime << "  " << implant_time[j] << endl;

                            gatedimplant_tree->Fill();

//                            imp_times->Fill(implant_time[j]);
                            counter++;
                        }
                    }
                }
            }
        }


    std::set<int> filled_germtree{};
    std::set<int> filled_aidadecaytree{};

// Decays in coincidence with Germanium
        if(aidadecayhits > 0 && germaniumhits > 0) {
            for (int i = 0; i < aidadecayhits; i++) {
                if (decay_dssd[i] == 1 && decay_cluster_size_x[i] == 1 && decay_cluster_size_y[i] == 1 && TMath::Abs(decay_energy_x[i] - decay_energy_y[i]) < 150 ) {
                    for (int j = 0; j < germaniumhits; j++) {
                        if (germanium_det[j] <= 12 && germanium_cry[j] <= 2 && germanium_energy[j] > 0) {
                            if ((decay_time[i] - germanium_abs_ev_time[j]) > 14458 && (decay_time[i] - germanium_abs_ev_time[j]) < 16458) {
                                if (filled_germtree.count(j) == 0) {
                                    germanium_data.time = germanium_abs_ev_time[j];
                                    double energy = germanium_energy[j];
                                    germanium_data.energy = energy;
                                    germanium_data.sp = spflag;
                                    germanium_data.bp = bpflag;
                                    germanium_tree->Fill();
                                }
                                filled_germtree.insert(j);
                                if(germanium_energy[j] > 1035 && germanium_energy[j] < 1045){
                                    aida_decay_data.time = decay_time[i];
                                    aida_decay_data.x = decay_x[i];
                                    aida_decay_data.y = decay_y[i];
                                    aida_decay_data.sp = spflag;
                                    aida_decay_data.bp = bpflag;
                                    decay_tree->Fill();
                                    
                                }
                                filled_aidadecaytree.insert(i);
                            }
                        }
                    }
                }               
            }
        }

        // Show the progress of the loop
        if (reader.GetCurrentEntry() % 1000 == 0) {
            int progress = (reader.GetCurrentEntry() * 100) / totalEntries;
            char spin = spinner[reader.GetCurrentEntry() / 1000 % 4];
            std::cout << "\rProcessing the tree " << reader.GetCurrentEntry() << " (" << progress << "%) " << spin << std::flush;
        }
        
    }


    // Write the new tree to the file
    // germanium_energy_hist->Write();
    // aida_implant_xy->Write();
    // aida_implant_decay_time->Write();
    // aida_wr_times->Write();
    // germanium_decay_energy->Write();
    // aida_decay_xy->Write();

    cout << "# of 166Tb implants:  " << counter << endl;
    
    implant_tree->Write();
    gatedimplant_tree->Write();
    decay_tree->Write();
    germanium_tree->Write();

    // Close the file
    file->Close();
    outputFile->Close();
    delete file;
    delete outputFile;
}