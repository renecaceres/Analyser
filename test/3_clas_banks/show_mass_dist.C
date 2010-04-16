void show_mass_dist()
{
    TFile *file_f = new TFile("particle_mass_dist.root");

    TH2F *hm = (TH2F *) file_f->Get("mass_dist");
    TProfile *pm = (TProfile *) file_f->Get("mass_dist_p");

    TCanvas *cm = new TCanvas("cm", "Mass", 1000, 500);
    cm->Divide(2, 1);

    pm->SetLineColor(4);

    cm->cd(1);
    hm->Draw();
    cm->cd(2)->SetBorderMode(0);
    pm->Draw();
}
