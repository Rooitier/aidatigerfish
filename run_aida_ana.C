void run_aida_ana(){

    TChain t("evt");

    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/*aidaana.root");
    // t.Add("/lustre/gamma/jeroen/S100/cluster/trees/*aidaananonts.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0001_aidaana.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0002_aidaana.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0003_aidaana.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0004_aidaana.root");
    t.Add("/lustre/gamma/jeroen/S100/cluster/trees/162Eu_new_0025_0005_aidaana.root");
    
    TProof::Open("workers=5");
    t.SetProof();

    t.Process("/u/jbormans/S100/analysis/aida_ana/aida_ana.C","/u/jbormans/S100/analysis/aida_ana/aida_ana.root");
}
