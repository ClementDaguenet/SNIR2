#ifndef BARRERONDE_H
#define BARRERONDE_H

#include "barre.h"

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const int _longueur, const float _densite, const int _diametre);
    virtual ~BarreRonde();
    virtual int CalculerSection();
    virtual void AfficherCaracteristiques();
    virtual double CalculerMasse();
protected:
    int diametre;
    float sectionRonde;
};

#endif // BARRERONDE_H
