#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "TIdentificator.h"

using namespace std;

const Double_t kFidThetaMax = 54;

//For theta_min calculation for electron
const Double_t kThetaPar0[6] = {15        , 15        ,  15       , 15        ,  13       ,  13};
const Double_t kThetaPar1[6] = {-0.425145 , -1.02217  , -0.7837   , -1.47798  ,   3.47361 ,   3.5714};
const Double_t kThetaPar2[6] = {-0.666294 , -0.616567 , -0.673602 , -0.647113 ,  -0.34459 ,  -0.398458};
const Double_t kThetaPar3[6] = { 5.73077  ,  5.51799  ,  8.05224  ,  7.74737  ,   8.45226 ,   9.54265};
const Double_t kThetaPar4[6] = {10.4976   , 14.0557   , 15.2178   , 16.7291   , -63.4556  , -22.649};
const Double_t kThetaPar5[6] = {-1.13254  , -1.16189  , -2.08386  , -1.79939  ,  -3.3791  ,  -1.89746};

//For parameter 0 of the phi_min calculation for electron
const Double_t kFidPar0Low0[6] = {25     ,25       ,25       ,24.6345 ,23.4731 ,24.8599};
const Double_t kFidPar0Low1[6] = {-12    ,-12      ,-12      ,-12     ,-12     ,-12};
const Double_t kFidPar0Low2[6] = {0.5605 ,0.714261 ,0.616788 ,0.62982 ,1.84236 ,1.00513};
const Double_t kFidPar0Low3[6] = {4.4    ,4.4      ,4.4      ,4.4     ,4.4     ,4.4};

//For parameter 1 of the phi_min calculation for electron
const Double_t kFidPar1Low0[6] = {2.1945    ,4        ,3.3352  ,2.22769   ,1.63143   ,3.19807};
const Double_t kFidPar1Low1[6] = {1.51417   ,1.56882  ,2       ,2         ,1.90179   ,0.173168};
const Double_t kFidPar1Low2[6] = {-0.354081 ,-2       ,-2      ,-0.760895 ,-0.213751 ,-0.1};
const Double_t kFidPar1Low3[6] = {0.5       ,0.5      ,1.01681 ,1.31808   ,0.786844  ,1.6};

//For parameter 0 of the phi_max calculation for electron
const Double_t kFidPar0High0[6] = {25       ,25       ,25       ,25       ,23.7067 ,25};
const Double_t kFidPar0High1[6] = {-8       ,-10.3277 ,-12      ,-11.3361 ,-12     ,-11.4641};
const Double_t kFidPar0High2[6] = {0.479446 ,0.380908 ,0.675835 ,0.636018 ,2.92146 ,0.55553};
const Double_t kFidPar0High3[6] = {4.8      ,4.79964  ,4.4      ,4.4815   ,4.4     ,4.41327};

//For parameter 1 of the phi_max calculation for electron
const Double_t kFidPar1High0[6] = {3.57349  ,3.02279      ,2.02102    ,3.1948    ,3.0934    ,2.48828};
const Double_t kFidPar1High1[6] = {2        ,0.966175     ,2          ,0.192701  ,0.821726  ,2};
const Double_t kFidPar1High2[6] = {-2       ,-2           ,-1.70021   ,-1.27578  ,-0.233492 ,-2};
const Double_t kFidPar1High3[6] = {0.5      ,0.527823     ,0.68655    ,1.6       ,1.6       ,0.70261};


//ClassImp(TIdentificator);



TIdentificator::TIdentificator(TClasTool *CT)
    : kEbeam(5.014), kMpi(0.139570), kGOOD(-1000.)
{
    this->fCT = CT;
}



TIdentificator::~TIdentificator()
{
    fCT = 0;
}



Double_t TIdentificator::Id(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
        return fEVNT->Id;
    } else {                            // Fix this in case k != 1
        fGSIM = (TGSIMClass *) fCT->GetBankRow("GSIM", k);
        return fGSIM->Id;
    }
}



Double_t TIdentificator::Px(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
        return fEVNT->Px;
    } else {                            // Fix this in case k != 1
        fGSIM = (TGSIMClass *) fCT->GetBankRow("GSIM", k);
        return fGSIM->Px;
    }
}



Double_t TIdentificator::Py(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
        return fEVNT->Py;
    } else {                            // Fix this in case k != 1
        fGSIM = (TGSIMClass *) fCT->GetBankRow("GSIM", k);
        return fGSIM->Py;
    }
}



Double_t TIdentificator::Pz(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
        return fEVNT->Pz;
    } else {                            // Fix this in case k != 1
        fGSIM = (TGSIMClass *) fCT->GetBankRow("GSIM", k);
        return fGSIM->Pz;
    }
}



Double_t TIdentificator::Nphe(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if(fEVNT->Ccstat >= 1) {
        Int_t ccst = fEVNT->Ccstat - 1;
        fCCPB = (TCCPBClass *) fCT->GetBankRow("CCPB", ccst);
        return fCCPB->Nphe;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::Chi2CC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Ccstat >=1) {
        Int_t cc_stat = fEVNT->Ccstat - 1;
        fCCPB = (TCCPBClass *) fCT->GetBankRow("CCPB", cc_stat);
        return fCCPB->Chi2cc;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::CCStatus(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Ccstat >= 1) {
        Int_t cc_stat = fEVNT->Ccstat - 1;
        fCCPB = (TCCPBClass *) fCT->GetBankRow("CCPB", cc_stat);
        return fCCPB->Status;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::DCStatus(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    if (fEVNT->Dcstat >= 1) {
        Int_t dc_stat = fEVNT->Dcstat - 1;
        fDCPB = (TDCPBClass *) fCT->GetBankRow("DCPB", dc_stat);
        return fDCPB->Status;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::Etot(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Ecstat >= 1) {
        Int_t ec_stat= fEVNT->Ecstat - 1;
        fECPB = (TECPBClass *) fCT->GetBankRow("ECPB", ec_stat);
        return fECPB->Etot;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::Ein(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Ecstat >= 1) {
        Int_t ec_stat= fEVNT->Ecstat - 1;
        fECPB = (TECPBClass *) fCT->GetBankRow("ECPB", ec_stat);
        return fECPB->Ein;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::Eout(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Ecstat >= 1) {
        Int_t ec_stat= fEVNT->Ecstat - 1;
        fECPB = (TECPBClass *) fCT->GetBankRow("ECPB", ec_stat);
        return fECPB->Eout;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::ECStatus(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    if (fEVNT->Ecstat >= 1) {
        Int_t ec_stat = fEVNT->Ecstat - 1;
        fECPB = (TECPBClass *) fCT->GetBankRow("ECPB", ec_stat);
        return fECPB->Status;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::PathSC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Scstat >= 1) {
        Int_t sc_stat = fEVNT->Scstat - 1;
        fSCPB = (TSCPBClass *) fCT->GetBankRow("SCPB", sc_stat);
        return fSCPB->Path;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::TimeSC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Scstat >= 1) {
        Int_t sc_stat = fEVNT->Scstat - 1;
        fSCPB = (TSCPBClass *) fCT->GetBankRow("SCPB", sc_stat);
        return fSCPB->Time;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::EdepSC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Scstat >= 1) {
        Int_t sc_stat = fEVNT->Scstat - 1;
        fSCPB = (TSCPBClass *) fCT->GetBankRow("SCPB", sc_stat);
        return fSCPB->Edep;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::SCStatus(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);

    if (fEVNT->Scstat >= 1) {
        Int_t sc_stat = fEVNT->Scstat -1;
        fSCPB = (TSCPBClass *) fCT->GetBankRow("SCPB", sc_stat);
        return fSCPB->Status;
    } else {
        return kGOOD;
    }
}



Double_t TIdentificator::Moment(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
        return sqrt(fEVNT->Px * fEVNT->Px + fEVNT->Py * fEVNT->Py +
                    fEVNT->Pz * fEVNT->Pz);
    } else {                            // Fix this in case k != 1
        fGSIM = (TGSIMClass *) fCT->GetBankRow("GSIM", k);
        return sqrt(fGSIM->Px * fGSIM->Px + fGSIM->Py * fGSIM->Py +
                    fGSIM->Pz * fGSIM->Pz);
    }
}



Double_t TIdentificator::Mass2(Int_t k)
{
      return Moment(k) * Moment(k) * (pow(Betta(k), -2) - 1);
}



Double_t TIdentificator::ThetaPQ(Int_t k, Bool_t kind)
{
    if (kind == 0) {
        return acos(Pz(k) / Moment(k));
    } else {                            // Fix this in case k != 1
        return acos(Pz(k,1) / Moment(k,1));
    }
}



Double_t TIdentificator::CosThetaPQ(Int_t k, Bool_t kind)
{
    if (kind == 0)
        return (Pz(k) * (kEbeam - Pz(0)) - Px(k) * Px(0) - Py(k) * Py(0)) /
                            (sqrt(Nu() * Nu() + Q2()) * Moment(k));
    else                                // Fix this in case k != 1
        return (Pz(k,1) * (kEbeam - Pz(0,1)) - Px(k,1) * Px(0,1) -
                Py(k,1) * Py(0,1)) /
                            (sqrt(Nu(1) * Nu(1) + Q2(1)) * Moment(k,1));
}



Double_t TIdentificator::PTrans2PQ(Int_t k, Bool_t kind)
{
    if (kind == 0)
        return Moment(k) * Moment(k) *
                            (1 - CosThetaPQ(k) * CosThetaPQ(k));
    else                                // Fix this in case k != 1
        return Moment(k,1) * Moment(k,1) *
                            (1 - CosThetaPQ(k,1) * CosThetaPQ(k,1));
}



Double_t TIdentificator::PLong2PQ(Int_t k, Bool_t kind)
{
    if (kind == 0)
        return Moment(k) * Moment(k) * CosThetaPQ(k) * CosThetaPQ(k);
    else                                // Fix this in case k != 1
        return Moment(k,1) * Moment(k,1) * CosThetaPQ(k,1) * CosThetaPQ(k,1);
}



Double_t TIdentificator::Q2(Bool_t kind)
{
    if (kind == 0) {
        return 4. * kEbeam * Moment(0) *
                            sin(ThetaPQ(0)/2) * sin(ThetaPQ(0)/2);
    } else {                            // Fix this in case k != 1
        return 4. * kEbeam * Moment(0,1) *
                            sin(ThetaPQ(0,1)/2) * sin(ThetaPQ(0,1)/2);
    }
}



Double_t TIdentificator::W(Bool_t kind)
{
    if (kind == 0) {
        return sqrt(0.938 * 0.938 + 2 * 0.938 * Nu() - Q2());
    } else {                            // Fix this in case k != 1
        return sqrt(0.938 * 0.938 + 2 * 0.938 * Nu(1) - Q2(1));
    }
}



Double_t TIdentificator::Nu(Bool_t kind)
{
    if (kind == 0) {
        return kEbeam - Moment(0);
    } else {                            // Fix this in case k != 1
        return kEbeam - Moment(0,1);
    }
}




Double_t TIdentificator::ZhPi(Int_t k, Bool_t kind, Double_t Mass)
{
    if (kind == 0)
        return sqrt(Mass * Mass + Moment(k) * Moment(k)) / Nu(fCT);
    else                                // Fix this in case k != 1
        return sqrt(Mass * Mass + Moment(k,1) * Moment(k,1)) / Nu(1);
}



Double_t TIdentificator::TimeCorr4(Double_t mass, Int_t k)
{
    return (PathSC(0)/30.) - TimeSC(0) + TimeSC(k) - 0.08 -
                (PathSC(k) / 30.) * sqrt(pow(mass/Moment(k),2) + 1);
}



TString TIdentificator::GetCategorization(Int_t k)
{
    Int_t number_dc = fCT->GetNRows("DCPB");
    Int_t number_cc = fCT->GetNRows("CCPB");
    Int_t number_sc = fCT->GetNRows("SCPB");
    Int_t number_ec = fCT->GetNRows("ECPB");

    TString partId;

    partId = "not recognized";

    if (number_dc != 0) {
        if (k == 0 &&
                    Status(0) > 0 && Status(0) < 100 &&
                    Charge(0) == -1 &&
                    number_cc != 0 && number_ec != 0 && number_sc != 0 &&
                    StatCC(0) > 0 && StatSC(0) > 0 &&
                    StatDC(0) > 0 && StatEC(0) > 0 &&
                    DCStatus(0) > 0 && SCStatus(0) == 33 &&
                    Nphe(0) > 25 &&
                    Etot(0) / 0.27 + 0.4 > Moment(0) &&
                    Etot(0) / 0.27 - 0.4 < Moment(0) &&
                    Ein(0) + Eout(0) > 0.8 * 0.27 * Moment(0) &&
                    Ein(0) + Eout(0) < 1.2 * 0.27 * Moment(0) &&
                    FidCheckCut() == 1)
            partId = "electron";

        //positive particles
        if (k > 0) {
            if (Charge(k) == 1 &&
                        Status(k) > 0 && Status(k) < 100 &&
                        StatDC(k) > 0 && DCStatus(k) > 0) {
                if (Moment(k)>=2.7) {
                    if (number_cc != 0 && StatCC(k) > 0 &&
                                Nphe(k) > 25 && Chi2CC(k) < 5 / 57.3)
                        partId = "high energy pion +";
                }

                if (Moment(k) < 2.7) {
                    if (number_sc != 0 && StatSC(k) > 0 &&
                                ((Moment(k) < 1 &&
                                    TimeCorr4(0.139,k) >= -1.46 &&
                                    TimeCorr4(0.139,k) <= 0.15) ||
                                (Moment(k) >=1 &&
                                    TimeCorr4(0.139,k) >= -1.38 &&
                                    TimeCorr4(0.139,k) <= 0.53)))
                        partId = "low energy pion +";
                }

                if (Moment(k) < 2.) {
                    if (number_sc != 0 && StatSC(k) > 0 &&
                                ((Moment(k) >= 1. &&
                                    TimeCorr4(0.938,k) >= -0.69 &&
                                    TimeCorr4(0.938,k) <= 1.38) ||
                                (Moment(k) < 1. &&
                                    TimeCorr4(0.938,k) >= -3.78 &&
                                    TimeCorr4(0.938,k) <= 6.75)))
                        partId = "low energy proton";
                }

                if (Charge(k) == 1 && number_cc != 0 &&
                            number_ec != 0 && number_sc != 0 &&
                            StatCC(k) > 0 && StatSC(k) > 0 &&
                            StatDC(k) > 0 && StatEC(k) > 0 &&
                            DCStatus(k) > 0 && Nphe(k) > 25 &&
                            Etot(k) / 0.27 + 0.4 > Moment(k) &&
                            Etot(k) / 0.27 - 0.4 < Moment(k) &&
                            Ein(k) + Eout(k) > 0.8 * 0.27 * Moment(k) &&
                            Ein(k) + Eout(k) < 1.2 * 0.27 * Moment(k))
                    partId = "positron";
            }
        }
    }

    return partId;
}



Double_t TIdentificator::FidTheta(Int_t k, Bool_t kind)
{
    Double_t fid_theta_val;

    if (kind == 0)
    {
        TVector3 v3p(Px(k), Py(k), Pz(k));
        fid_theta_val = v3p.Theta() * 180 / TMath::Pi();
    } else {
        TVector3 v3p(Px(k,1), Py(k,1), Pz(k,1));
        fid_theta_val = v3p.Theta() * 180 / TMath::Pi();
    }

    return fid_theta_val;
}



Double_t TIdentificator::FidThetaMin()
{
    Int_t sector = FidSector(0);

    Double_t theta_min_val = kThetaPar0[sector] +
            kThetaPar1[sector] / pow(Moment(0),2) +
            kThetaPar2[sector] * Moment(0) +
            kThetaPar3[sector] / Moment(0) +
            kThetaPar4[sector] *exp(kThetaPar5[sector] * Moment(0));

    return theta_min_val;
}



Double_t TIdentificator::FidFunc(Int_t side, Int_t param)
{
    Int_t sector = FidSector(0);
    Double_t fid_func_val = 0.0; // dummy value to avoid that uninitialized warning

    if (side == 0 && param==0)
        fid_func_val = kFidPar0Low0[sector] +
                    kFidPar0Low1[sector] * exp(kFidPar0Low2[sector] *
                            (Moment(0) - kFidPar0Low3[sector]));
    else if (side == 1 && param==0)
        fid_func_val = kFidPar0High0[sector] +
                    kFidPar0High1[sector] * exp(kFidPar0High2[sector] *
                            (Moment(0) - kFidPar0High3[sector]));
    else if (side == 0 && param==1)
        fid_func_val=kFidPar1Low0[sector] +
                    kFidPar1Low1[sector] * Moment(0) *
                    exp(kFidPar1Low2[sector] * pow((Moment(0) -
                                kFidPar1Low3[sector]),2));
    else if (side == 1 && param==1)
        fid_func_val = kFidPar1High0[sector] +
                    kFidPar1High1[sector] * Moment(0) *
                    exp(kFidPar1High2[sector] * pow((Moment(0) -
                                kFidPar1High3[sector]),2));

    return fid_func_val;
}												



Double_t TIdentificator::FidPhi(Int_t k, Bool_t kind)
{
    Double_t fid_phi_val;

    if (kind == 0) {
        TVector3 v3p(Px(k), Py(k), Pz(k));
        fid_phi_val = v3p.Phi() * 180 / TMath::Pi();
    } else {
        TVector3 v3p(Px(k,1), Py(k,1), Pz(k,1));
        fid_phi_val = v3p.Phi() * 180 / TMath::Pi();
    }

    if (fid_phi_val < -30)
        fid_phi_val += 360;
    else if (fid_phi_val > 330)
        fid_phi_val -= 360;

    return fid_phi_val;
}



Double_t TIdentificator::FidPhiMin()
{
    Int_t sector = FidSector(0);
    Double_t fid_phi_min_val;

    if (FidTheta(0) <= FidThetaMin()) {
        fid_phi_min_val = 60. * sector;
        return fid_phi_min_val;
    } else {
        fid_phi_min_val = 60. * sector - FidFunc(0,0) *
                (1 - 1 / (1 + (FidTheta(0) - FidThetaMin()) / FidFunc(0,1)));
        return fid_phi_min_val;
    }
}



Double_t TIdentificator::FidPhiMax()
{
    Int_t sector = FidSector(0);
    Double_t fid_phi_max_val;

    if (FidTheta(0) <= FidThetaMin()){
        fid_phi_max_val = 60. * sector;
        return fid_phi_max_val;
    } else {
        fid_phi_max_val = 60. * sector + FidFunc(1,0) *
                (1 - 1 / (1 + (FidTheta(0) - FidThetaMin()) / FidFunc(1,1)));
        return fid_phi_max_val;
    }
}



Bool_t TIdentificator::FidCheckCut()
{
    if (FidTheta(0) > FidThetaMin() &&
                FidPhi(0) > FidPhiMin() &&
                FidPhi(0) < FidPhiMax())
        return 1;                               // Fiducial Cut passed
    else
        return 0;                               // Fiducial Cut not passed
}



Int_t TIdentificator::FidSector(Int_t k, Bool_t kind)
{
    Int_t sector;

    if (kind == 0) {
        if (FidPhi(k) != 330) {
            sector = int((FidPhi(k) + 90) / 60) - 1;
            return sector;
        } else {
            return 5;
        }
    }
    else {
        if (FidPhi(k,1) != 330) {
            sector = int((FidPhi(k,1) + 90) / 60) - 1;
            return sector;
        } else {
            return 5;
        }
    }
}
