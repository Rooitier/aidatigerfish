void run_bgam(){
    
    
    TChain t("evt");

    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0024_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0025_*.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0026_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0027_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0028_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0029_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0030_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0033_*.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0034_*.root");

    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0026_0001.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0025_0003.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0025_0004.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu/162Eu_new_0025_0005.root");

    
    TProof::Open("workers=64");
    t.SetProof();

    // t.Process("bgam.C","test.root");
    t.Process("bgam.C","bplastaida.root");


}