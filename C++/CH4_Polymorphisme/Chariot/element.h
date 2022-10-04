#ifndef ELEMENT_H
#define ELEMENT_H

#include "vecteur.h"

class Element
{
public:
    Element(const int _vitesse = 1);
    virtual ~Element();
    virtual void Afficher();
    virtual double ObtenirLongueur() = 0;
    virtual double ObtenirDuree() = 0;
    virtual Vecteur ObtenirVecteurArrivee() = 0;
    int getNumero() const;
    void setNumero(int newNumero);
protected:
    int numero;
    int vitesse;
};

#endif // ELEMENT_H
