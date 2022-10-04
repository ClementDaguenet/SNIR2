#ifndef PAUSE_H
#define PAUSE_H

#include "element.h"

class Pause : public Element
{
public:
    Pause(const int _tempsAttente);
    void Afficher();
    virtual double ObtenirLongueur();
    virtual double ObtenirDuree();
    virtual Vecteur ObtenirVecteurArrivee();
private:
    double longueur;
    double angle;
    int tempsAttente;
};

#endif // PAUSE_H
