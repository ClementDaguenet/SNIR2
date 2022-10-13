#ifndef BARRECARREE_H
#define BARRECARREE_H

#include "barre.h"

class BarreCarree : public Barre
{
public:
    BarreCarree(const string _reference, const int _longueur,const float _densite, const int _largeur);
    virtual ~BarreCarree();
    virtual void AfficherCaracteristiques();
    virtual int CalculerSection();
    virtual double CalculerMasse();
protected:
    int largeur;
    float sectionCarree;
};

#endif // BARRECARREE_H
