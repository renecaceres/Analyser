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

#ifndef CLASTOOL_TCCPBClass
#include "TECPBClass.h"
#endif

//class TClasTool;
//class TEVNTClass;
//class TCCPBClass;


class TIdentificator {
protected:
    const Double_t kEbeam;
    const Double_t kMpi;
    const Double_t kGOOD;

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

    Double_t Betta(Int_t);
    Float_t NEvent();
    Double_t Id(Int_t, Bool_t = 0);
    Double_t Charge(Int_t);

    Int_t StatCC(Int_t);
    Int_t StatSC(Int_t);
    Int_t StatDC(Int_t);
    Int_t StatEC(Int_t);
    Double_t Status(Int_t);
    Double_t CCStatus(Int_t);
    Double_t SCStatus(Int_t);
    Double_t ECStatus(Int_t);
    Double_t DCStatus(Int_t);

    Double_t Moment(Int_t, Bool_t = 0);
    Double_t Mass2(Int_t);

    Double_t Q2(Bool_t = 0);
    Double_t W(Bool_t = 0);
    Double_t Nu(Bool_t = 0);
    Double_t Theta(Int_t, Bool_t = 0);
    Double_t Chi2CC(Int_t);

    Double_t Px(Int_t, Bool_t = 0);
    Double_t Py(Int_t, Bool_t = 0);
    Double_t Pz(Int_t, Bool_t = 0);
    Double_t Nphe(Int_t);

    Double_t X(Int_t);
    Double_t Y(Int_t);
    Double_t Z(Int_t);

    Double_t Pt2(Int_t, Bool_t = 0);
    Double_t Pt2Long(Int_t, Bool_t = 0);
    Double_t CosThetaPq(Int_t, Bool_t = 0);
    Double_t Zpi(Int_t, Bool_t = 0, Double_t = 0.139);

    Double_t TimeCorr4(Double_t, Int_t);
    Double_t PathSC(Int_t k);
    Double_t TimeSC(Int_t k);
    Double_t EdepSC(Int_t k);

    Double_t Etot(Int_t k);
    Double_t Ein(Int_t k);
    Double_t Eout(Int_t k);

    TString GetCategorization(Int_t);

    Double_t FidTheta(Int_t, Bool_t = 0);
    Double_t FidPhi(Int_t, Bool_t = 0);
    Int_t FidSector(Int_t, Bool_t = 0);
    Double_t FidThetaMin();
    Double_t FidFunc(Int_t, Int_t);
    Double_t FidPhiMin();
    Double_t FidPhiMax();
    Bool_t FidCheckCut();
};

#endif
