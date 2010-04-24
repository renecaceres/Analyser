#ifndef TIDENTIFICATOR_INLINES_H
#define TIDENTIFICATOR_INLINES_H


inline Float_t TIdentificator::NEvent()
{
    return ((THEADERClass *) fCT->GetHEADER())->GetNEvent();
}



inline Double_t TIdentificator::Betta(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Betta;
}



inline Double_t TIdentificator::Charge(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Charge;
}



inline Double_t TIdentificator::X(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->X;
}



inline Double_t TIdentificator::Y(Int_t k) {
    fEVNT = (TEVNTClass*)fCT->GetBankRow("EVNT",k);
    return fEVNT->Y;
}



inline Double_t TIdentificator::Z(Int_t k) {
    fEVNT = (TEVNTClass*)fCT->GetBankRow("EVNT",k);
    return fEVNT->Z;
}



inline Int_t TIdentificator::StatCC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Ccstat;
}



inline Int_t TIdentificator::StatSC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Scstat;
}



inline Int_t TIdentificator::StatDC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Dcstat;
}



inline Int_t TIdentificator::StatEC(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Ecstat;
}



inline Double_t TIdentificator::Status(Int_t k)
{
    fEVNT = (TEVNTClass *) fCT->GetBankRow("EVNT", k);
    return fEVNT->Status;
}


#endif
