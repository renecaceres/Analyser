{
    TFile *file = new TFile("particle_histograms.root");

    TH2F *h1 = (TH2F *) file->Get("electron_2d");
    TH2F *h2 = (TH2F *) file->Get("he_pion_2d");
    TH2F *h3 = (TH2F *) file->Get("le_pion_2d");
    TH2F *h4 = (TH2F *) file->Get("le_proton_2d");
    TH2F *h5 = (TH2F *) file->Get("positron_2d");

    TCanvas *ch = new TCanvas("ch", "Histograms", 600, 800);
    ch->Divide(2, 3);

    h1->SetMarkerColor(kGreen+3);
    h1->SetName("Electron");

    h2->SetMarkerColor(kGreen+3);
    h2->SetName("High Energy #pi^{+}");

    h3->SetMarkerColor(kGreen+3);
    h3->SetName("Low Energy #pi^{+}");

    h4->SetMarkerColor(kGreen+3);
    h4->SetName("Low Energy Proton");

    h5->SetMarkerColor(kGreen+3);
    h5->SetName("Positron");

    ch->cd(1);
    h1->Draw();
    ch->cd(2);
    h5->Draw();
    ch->cd(3);
    h2->Draw();
    ch->cd(4);
    h3->Draw();
    ch->cd(5);
    h4->Draw();
    ch->cd(6)->SetBorderMode(0);
}
