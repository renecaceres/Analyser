#include "Riostream.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TApplication.h"
#include "TROOT.h"
#include <math.h>

extern void InitGui();
VoidFuncPtr_t initfuncs[] = {InitGui, 0};

TROOT my_app("myapp", "myapp", initfuncs);

int main(int argc, char **argv)
{
    gROOT->Reset();
    TApplication *rootapp = new TApplication("Tarea1", &argc, argv);

    // Get the root file
    TFile *f = new TFile("two_pion_C_data.root");

    // Get the tree from file
    TTree *t1 = (TTree *) f->Get("pi_data");

    // Get the tree branches
    Float_t Q2, px[5], py[5], pz[5];
    Int_t nmb_Pion;
    Int_t nentries = (Int_t) t1->GetEntries();

    t1->SetBranchAddress("Q2", &Q2);
    t1->SetBranchAddress("Px", &px);
    t1->SetBranchAddress("Py", &py);
    t1->SetBranchAddress("Pz", &pz);
    t1->SetBranchAddress("nmb_Pion", &nmb_Pion);

    // The histograms for Q12 and Q12_mix
    TH1F *h1 = new TH1F("Q12", "Q12", 300, 0, 3);
    TH1F *h2 = new TH1F("Q12_mix", "Q12_mix", 300, 0, 3);

    Float_t q, cx, cy, cz;
    Float_t temp1x, temp1y, temp1z, tempx, tempy, tempz;

    // Fill the histograms
    t1->GetEntry(0);

    cx = px[0] - px[1];
    cy = py[0] - py[1];
    cz = pz[0] - pz[1];
    q = sqrt(cx * cx  +  cy * cy  +  cz * cz);
    
    tempx = px[0];
    tempy = py[0];
    tempz = pz[0];
    temp1x = px[1];
    temp1y = py[1];
    temp1z = pz[1];

    h1->Fill(q);  
    cout << "Procesando datos...\n";
    for (Int_t i = 1; i < nentries; i++) {
        t1->GetEntry(i);

        cx = px[0] - px[1];
        cy = py[0] - py[1];
        cz = pz[0] - pz[1];
        q = sqrt(cx * cx  +  cy * cy  +  cz * cz);
        
        h1->Fill(q);  

        cx = tempx - px[1];
        cy = tempy - py[1];
        cz = tempz - pz[1];
        q = sqrt(cx * cx  +  cy * cy  +  cz * cz);
        h2->Fill(q);  

        tempx = px[0];
        tempy = py[0];
        tempz = pz[0];
    }

    cx = tempx - temp1x;
    cy = tempy - temp1y;
    cz = tempz - temp1z;
    q = sqrt(cx * cx  +  cy * cy  +  cz * cz);
    h2->Fill(q); 
     

    TCanvas *c = new TCanvas("c", "Tarea 1", 1280, 800);
    cout << "Generando histogramas...\n";
    c->Divide(2, 2);    

    // Show Q12 histogram
    c->cd(1);
    h1->SetLineColor(kRed);
    h1->Draw();

    // Show Q12_mix histogram
    c->cd(2);
    h2->SetLineColor(kRed);
    h2->Draw();

    // The histogram for R
    TH1F *h3 = (TH1F*) h1->Clone();
    h3->SetTitle("R");
    h3->SetName("R");
    h3->Sumw2();
    h3->Divide(h1, h2);
    h3->SetLineColor(kBlue);

    // Show R histogram
    c->cd(3);
    h3->Draw();

//    rootapp->Run(kTRUE);
    rootapp->Run();
    return 0;
}
