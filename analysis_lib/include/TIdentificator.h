#ifndef TIDENTIFICATOR_H
#define TIDENTIFICATOR_H


#ifndef CLASTOOL_THEADERClass
#include "THEADERClass.h"
#endif

#ifndef CLASTOOL_TClasTool
#include "TClasTool.h"
#endif

#ifndef CLASTOOL_TDSTReader
#include "TDSTReader.h"
#endif

#ifndef CLASTOOL_TEVNTClass
#include "TEVNTClass.h"
#endif

#ifndef CLASTOOL_TCCPBClass
#include "TCCPBClass.h"
#endif

#ifndef CLASTOOL_TECPBClass
#include "TECPBClass.h"
#endif

#ifndef CLASTOOL_TGSIMClass
#include "TGSIMClass.h"
#endif

//class TClasTool;
//class TEVNTClass;
//class TCCPBClass;


class TIdentificator {
protected:
    const Double_t kEbeam;    // The energy of incoming electron beam
    const Double_t kMpi;      // The mass of the pion
    const Double_t kGOOD;     // The key for the exceptions (should be improved to avoid it at all !!!)

    TClasTool *fCT;
    TEVNTClass *fEVNT;
    TGSIMClass *fGSIM;
    TCCPBClass *fCCPB;
    TECPBClass *fECPB;
    TSCPBClass *fSCPB;
    TDCPBClass *fDCPB;
  
public:
    TIdentificator(TClasTool *);
    ~TIdentificator();

    // HEADER bank
    Float_t NEvent();

    // EVNT bank
    Double_t Betta(Int_t);
    Double_t Id(Int_t, Bool_t = 0);
    Double_t Charge(Int_t);
    Double_t Px(Int_t, Bool_t = 0);
    Double_t Py(Int_t, Bool_t = 0);
    Double_t Pz(Int_t, Bool_t = 0);
    Double_t X(Int_t);
    Double_t Y(Int_t);
    Double_t Z(Int_t);
    Int_t StatCC(Int_t); // CCPB key
    Int_t StatSC(Int_t); // SCPB key
    Int_t StatDC(Int_t); // DCPB key
    Int_t StatEC(Int_t); // ECPB key
    Double_t Status(Int_t); // Event general status

    // CCPB bank
    Double_t Nphe(Int_t);
    Double_t Chi2CC(Int_t);
    Double_t CCStatus(Int_t);

    // DCPB bank
    Double_t DCStatus(Int_t);

    // ECPB bank
    Double_t Etot(Int_t k);
    Double_t Ein(Int_t k);
    Double_t Eout(Int_t k);
    Double_t ECStatus(Int_t);

    // SCPB bank
    Double_t PathSC(Int_t k);
    Double_t TimeSC(Int_t k);
    Double_t EdepSC(Int_t k);
    Double_t SCStatus(Int_t);

    // Derived observables
    Double_t Moment(Int_t, Bool_t = 0);
    Double_t Mass2(Int_t);
    Double_t ThetaPQ(Int_t, Bool_t = 0);
    Double_t CosThetaPQ(Int_t, Bool_t = 0);
    Double_t PTrans2PQ(Int_t, Bool_t = 0);
    Double_t PLong2PQ(Int_t, Bool_t = 0);

    // Kinematic variables
    Double_t Q2(Bool_t = 0);
    Double_t W(Bool_t = 0);
    Double_t Nu(Bool_t = 0);
    Double_t ZhPi(Int_t, Bool_t = 0, Double_t = 0.139);

    // Correction functions
    Double_t TimeCorr4(Double_t, Int_t);

    // Particle Identification cuts
    TString GetCategorization(Int_t);

    // Fiducial Cut
    Double_t FidTheta(Int_t, Bool_t = 0);
    Double_t FidThetaMin();
    Double_t FidFunc(Int_t, Int_t);
    Double_t FidPhi(Int_t, Bool_t = 0);
    Double_t FidPhiMin();
    Double_t FidPhiMax();
    Bool_t FidCheckCut();
    Int_t FidSector(Int_t, Bool_t = 0);
};

#endif
