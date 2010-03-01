void create_file()
{
    if (!TClassTable::GetDict("Event")) {
            gSystem->Load("libEvent.so");
    }

    Int_t split  = 1;
    Int_t bufsize = 64000;

    if (split)  bufsize /= 4;

    TFile *hfile = new TFile("Event.root","RECREATE","TTree benchmark ROOT file");
    TTree *tree = new TTree("T","A ROOT tree with events");
    Event *event = new Event();


    TBranch *branch = tree->Branch("event", &event, bufsize, split);
    branch->SetAutoDelete(kFALSE);

    Float_t ptmin = 1;
    Int_t nevent = 400;
    Int_t arg5   = 600;

    for (Int_t ev = 0; ev < nevent; ev++) {
        event->Build(ev, arg5, ptmin);
        tree->Fill();
    }

    tree->Write();
    tree->Print();

    cout << endl << nevent << " events processed." << endl;
    hfile->Close();
}


void read_tree()
{
    if (!TClassTable::GetDict("Event")) {
            gSystem->Load("libEvent.so");
    }

    TFile *f = new TFile("Event.root");
    TTree *t = (TTree *) f->Get("T");
    t->Print();
    t->GetEntry(6);
    t->Show();
}
