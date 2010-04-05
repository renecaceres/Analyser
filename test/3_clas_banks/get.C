void show(Int_t type, TString name)
{
    TFile *file = new TFile("particle_data.root");
    TTree *tree = (TTree *) file->Get("data");

    TH2F *h1 = new TH2F(name, "Betta vs Momentum", 50, 0.0, 5.0, 50, 0.0, 1.2);

    Double_t b, m;
    Int_t id = 0;

    tree->SetBranchAddress("betta", &b);
    tree->SetBranchAddress("moment", &m);
    tree->SetBranchAddress("particle", &id);

    for (Int_t i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);
        if (id == type) {
            h1->Fill(m, b);
        }
    }

    h1->Draw();
}



void get(Int_t type = 1)
{
    TString name;

    if (type == 1)
        name = "electron";
    else if (type == 2)
        name = "high energy pion +";
    else if (type == 3)
        name = "low energy pion +";
    else if (type == 4)
        name = "low energy proton";
    else if (type == 5)
        name = "positron";

    show(type, name);
}



void get(TString name = "electron")
{
    Int_t type;

    if (name == "electron")
        type = 1;
    else if (name == "high energy pion +")
        type = 2;
    else if (name == "low energy pion +")
        type = 3;
    else if (name == "low energy proton")
        type = 4;
    else if (name == "positron")
        type = 5;

    show(type, name);
}
