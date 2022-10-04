#ifndef ARC_H
#define ARC_H

#include "element.h"

class Arc : public Element
{
public:
    Arc(const int _vitesse, const double _rayon, const double _angleDebut, const double _angleFin);
    void Afficher();
    virtual double ObtenirLongueur();
    virtual double ObtenirDuree();
    virtual Vecteur ObtenirVecteurArrivee();
protected:
    double rayon;
    float angleDebut;
    float angleFin;
};

#endif // ARC_H
