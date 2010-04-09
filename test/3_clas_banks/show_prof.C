{
    TFile *file_p = new TFile("particle_profiles.root");

    TProfile *p1 = (TProfile *) file_p->Get("electron_pro");
    TProfile *p2 = (TProfile *) file_p->Get("he_pion_pro");
    TProfile *p3 = (TProfile *) file_p->Get("le_pion_pro");
    TProfile *p4 = (TProfile *) file_p->Get("le_proton_pro");
    TProfile *p5 = (TProfile *) file_p->Get("positron_pro");

    TCanvas *cp = new TCanvas("cp", "Profiles", 600, 800);
    cp->Divide(2, 3);

    p1->SetLineColor(kOrange+7);
    p1->SetName("Electron");

    p2->SetLineColor(kOrange+7);
    p2->SetName("High Energy #pi^{+}");

    p3->SetLineColor(kOrange+7);
    p3->SetName("Low Energy #pi^{+}");

    p4->SetLineColor(kOrange+7);
    p4->SetName("Low Energy Proton");

    p5->SetLineColor(kOrange+7);
    p5->SetName("Positron");

    cp->cd(1);
    p1->Draw();
    cp->cd(2);
    p5->Draw();
    cp->cd(3);
    p2->Draw();
    cp->cd(4);
    p3->Draw();
    cp->cd(5);
    p4->Draw();
    cp->cd(6)->SetBorderMode(0);
}
