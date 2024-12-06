void run_noclust(){
    
    
    TChain t("evt");

    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/special/162Eu_noclustering/162Eu*.root");


    
    TProof::Open("workers=64");
    t.SetProof();

    t.Process("noclust.C","noclust.root");


}