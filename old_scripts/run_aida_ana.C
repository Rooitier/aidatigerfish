void run_aida_new(){

    TChain t("evt");

    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/*aidaana.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/*aidaananonts.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0001_aida.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0002_aida.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0003_aida.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0004_aida.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0005_aida.root");
    
    TProof::Open("workers=5");
    t.SetProof();

    t.Process("/u/jbormans/S100/analysis/aidatigerfish/aida_new.C","/u/jbormans/S100/analysis/aidatigerfish/results/aida_new.root");
}
