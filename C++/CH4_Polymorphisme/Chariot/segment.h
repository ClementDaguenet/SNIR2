#ifndef SEGMENT_H
#define SEGMENT_H

#include "element.h"
#include "vecteur.h"

class Segment : public Element
{
public:
    Segment(const int _vitesse, const double _longueur, double const _angle);
    void Afficher();
    virtual double ObtenirLongueur();
    virtual double ObtenirDuree();
    virtual Vecteur ObtenirVecteurArrivee();
protected:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
