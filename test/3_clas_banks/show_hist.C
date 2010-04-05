{
    TFile *file = new TFile("particle_histograms.root");

    TH2F *h1 = (TH2F *) file->Get("Electron");
    TH2F *h2 = (TH2F *) file->Get("High Energy Pion +");
    TH2F *h3 = (TH2F *) file->Get("Low Energy Pion +");
    TH2F *h4 = (TH2F *) file->Get("Low Energy Proton");
    TH2F *h5 = (TH2F *) file->Get("Positron");

    TCanvas *c = new TCanvas("c", "Histograms", 600, 800);
    c->Divide(2, 3);    

    c->cd(1);
    h1->Draw();
    c->cd(2);
    h5->Draw();
    c->cd(3);
    h2->Draw();
    c->cd(4);
    h3->Draw();
    c->cd(5);
    h4->Draw();
}
