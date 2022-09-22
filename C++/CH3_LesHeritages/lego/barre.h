/**
 * @file barre.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRE_H
#define BARRE_H

#include "libs.h"

class Barre
{
public:
    Barre(const string _nom, const float _densite, const string _reference, const int _longueur);
    ~Barre();
    int AfficherCaracteristiques();
protected:
    /// Le nom de la barre
    string nom;
    /// La densité de la barre
    float densite;
    /// La référence de la barre
    string reference;
    /// La longueur de la barre
    int longueur;
};

#endif // BARRE_H
