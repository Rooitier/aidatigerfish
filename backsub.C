#include <TH1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <string>

void backsub(const std::string& signal_file_name, const std::string& signal_hist_name,
             const std::string& background_file_name, const std::string& background_hist_name,
             const std::string& output_file_name) {
    // Open the ROOT files containing the histograms
    TFile *signal_file = TFile::Open(signal_file_name.c_str());
    TFile *background_file = TFile::Open(background_file_name.c_str());

    // Retrieve the signal and background histograms
    TH1D *h_signal = (TH1D*)signal_file->Get(signal_hist_name.c_str());
    TH1D *h_background = (TH1D*)background_file->Get(background_hist_name.c_str());

    TH1D *h_germ = (TH1D*)signal_file->Get("germanium_decay_energy");

    // Get integral between energy range in germanium energy histogram
    double germ_integral = h_germ->Integral(h_germ->FindBin(1035), h_germ->FindBin(1045));
    std::cout << "Integral between 1035 and 1045: " << germ_integral << std::endl;
    double germ_integral_2 = h_germ->Integral(h_germ->FindBin(1055), h_germ->FindBin(1065));
    std::cout << "Integral between 1055 and 1065: " << germ_integral_2 << std::endl;
    double peakcounts = 8667.0;
    peakcounts = 2286.0;

    // Normalize the signal histogram to the background histogram
    double signal_integral = h_signal->Integral();
    double background_integral = h_background->Integral();
    if (background_integral != 0) {
        h_background->Scale((germ_integral - peakcounts) / germ_integral_2);
        std::cout << "Scaling factor: " << (germ_integral - peakcounts) / germ_integral_2 << std::endl;
    }

    // Create a new histogram for the background-subtracted result
    TH1D *h_subtracted = (TH1D*)h_signal->Clone("h_subtracted");
    h_subtracted->Add(h_background, -1);

    // Draw the scaled signal and background histograms on the same canvas
    TCanvas *c1 = new TCanvas("c1", "Background Subtraction", 800, 600);
    h_signal->SetLineColor(kBlue);
    h_signal->Draw("hist");
    h_background->SetLineColor(kRed);
    h_background->Draw("hist same");

    // Draw the background-subtracted histogram on the same canvas
    h_subtracted->SetLineColor(kGreen);
    h_subtracted->Draw("hist same");

    // Save the result to a new file
    TFile *output_file = new TFile(output_file_name.c_str(), "RECREATE");
    h_signal->Write();
    h_background->Write();
    h_subtracted->Write();
    output_file->Close();

    // Clean up
    signal_file->Close();
    background_file->Close();
    delete signal_file;
    delete background_file;
    delete output_file;
    delete c1;
}