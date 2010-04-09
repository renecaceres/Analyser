#include "betta.C"

void show(Int_t type, TString name)
{
    TFile *file = new TFile("particle_data.root");
    TTree *tree = (TTree *) file->Get("data");

    TProfile *h1 = new TProfile(name, "Betta vs Momentum", 500, 0.0, 5.0, 0.0, 1.2);

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

    TCanvas *c = new TCanvas("c", "Profile");
    TF1 *fn = new TF1("betta", betta, 0, 5, 1);
    fn->SetParameter(0,0.000511);
    fn->SetLineColor(2);
    h1->SetLineColor(kBlue+1);
    h1->Fit("betta");
}



void getFit(Int_t type = 1)
{
    TString name;

    if (type == 1)
        name = "Electron";
    else if (type == 2)
        name = "High Energy #pi^{+}";
    else if (type == 3)
        name = "Low Energy #pi^{+}";
    else if (type == 4)
        name = "Low Energy Proton";
    else if (type == 5)
        name = "Positron";

    show(type, name);
}



void getFit(TString name = "electron")
{
    Int_t type;

    if (name == "electron") {
        name = "Electron";
        type = 1;
    } else if (name == "high energy pion +") {
        name = "High Energy #pi^{+}";
        type = 2;
    } else if (name == "low energy pion +") {
        type = 3;
        name = "Low Energy #pi^{+}";
    } else if (name == "low energy proton") {
        type = 4;
        name = "Low Energy Proton";
    } else if (name == "positron") {
        type = 5;
        name = "Positron";
    }

    show(type, name);
}
