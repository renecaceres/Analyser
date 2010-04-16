void mass_distribution ()
{
    gSystem->Load("libClasTool.so");
    gSystem->Load("libTIdentificator.so");

    TClasTool *input = new TClasTool();

    input->InitDSTReader("ROOTDSTR");
    input->AddFile("clas_42011_01_1.pass2.root");
    TIdentificator *t = new TIdentificator(input);
    Int_t nEntries = input->GetEntries();
    input->Next();

    TH2F *h = new TH2F("mass_dist", "Mass Distribution", 1000, 0.0, 5.0, 50, 0.0, 1.2);
    TProfile *p = new TProfile("mass_dist_p", "Mass Distribution", 1000, 0.0, 5.0, 0.0, 1.2);

    for (int k = 0; k < nEntries; k++) {
        int nRows = input->GetNRows("EVNT");
        for (int i = 0; i < nRows; i++)
            if (t->Charge(i) == 1 && t->StatSC(i) > 0) {
                h->Fill(t->Mass2(i), t->Moment(i));
                p->Fill(t->Mass2(i), t->Moment(i));
            }
        input->Next();
    };

    TFile *output_m = new TFile("particle_mass_dist.root","RECREATE","Particle Mass Distribution");
    h->Write();
    p->Write();
    output_m->Close();
    cout << "Done." << endl;
}
