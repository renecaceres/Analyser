#include "betta.C"

void show_fit()
{
    TFile *file_f = new TFile("particle_profiles.root");

    TProfile *f1 = (TProfile *) file_f->Get("electron_pro");
    TProfile *f2 = (TProfile *) file_f->Get("he_pion_pro");
    TProfile *f3 = (TProfile *) file_f->Get("le_pion_pro");
    TProfile *f4 = (TProfile *) file_f->Get("le_proton_pro");
    TProfile *f5 = (TProfile *) file_f->Get("positron_pro");

    TF1 *fn = new TF1("betta", betta, 0, 5, 1);
    fn->SetParameter(0,0.000511);

    TCanvas *cf = new TCanvas("cf", "Profiles", 600, 800);
    cf->Divide(2, 3);

    fn->SetLineColor(2);

    f1->SetLineColor(4);
    f1->SetName("Electron");

    f2->SetLineColor(4);
    f2->SetName("High Energy #pi^{+}");

    f3->SetLineColor(4);
    f3->SetName("Low Energy #pi^{+}");

    f4->SetLineColor(4);
    f4->SetName("Low Energy Proton");

    f5->SetLineColor(4);
    f5->SetName("Positron");


    cf->cd(1);
    f1->Fit("betta");
    cf->cd(2);
    f5->Fit("betta");
    cf->cd(3);
    f2->Fit("betta");
    cf->cd(4);
    f3->Fit("betta");
    cf->cd(5);
    f4->Fit("betta");
    cf->cd(6)->SetBorderMode(0);
}
