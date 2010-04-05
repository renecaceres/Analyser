{
    gSystem->Load("libClasBanks.so");
    gSystem->Load("libClasTool.so");
    gSystem->Load("libTIdentificator.so");
   

    TClasTool *f = new TClasTool();

    f->InitDSTReader("ROOTDSTR");
    f->AddFile("clas_42011_01_1.pass2.root");

    TIdentificator *t = new TIdentificator(f);

    Int_t n = f->GetEntries();

    TFile *file = new TFile("particle_data.root","RECREATE","Data of particles");
    TTree *tree = new TTree("data","Tree that holds the data");

    Double_t b, m;
    Int_t id = 0;

    tree->Branch("betta", &b, "b/D");
    tree->Branch("moment", &m, "m/D");
    tree->Branch("particle", &id, "id/I");

    f->Next();

    for (Int_t k = 0; k < n; k++) {
        Int_t nr = f->GetNRows("EVNT");
        for (Int_t i = 0; i < nr; i++) {
            if (t->GetCategorization(i) == "electron")
                id = 1;
            else if (t->GetCategorization(i) == "high energy pion +")
                id = 2;
            else if (t->GetCategorization(i) == "low energy pion +")
                id = 3;
            else if (t->GetCategorization(i) == "low energy proton")
                id = 4;
            else if (t->GetCategorization(i) == "positron")
                id = 5;
            else
                id = 0;
            m = t->Moment(i);
            b = t->Betta(i);
            tree->Fill();
        }
        f->Next();
    };

    file->Write();
    file->Close();
}
