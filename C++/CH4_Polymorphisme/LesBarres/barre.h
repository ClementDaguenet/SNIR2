#ifndef BARRE_H
#define BARRE_H

#include "libs.h"

class Barre
{
public:
    Barre(const string _reference, const int _longueur, const float _densite);
    virtual ~Barre();
    virtual void AfficherCaracteristiques();
    virtual double CalculerMasse() {return 0;}
protected:
    string reference;
    int longueur;
    float densite;
};

#endif // BARRE_H
