/**
 * @file barreronde.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRERONDE_H
#define BARRERONDE_H

#include "barre.h"

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _nom, const float _densite, const string _reference, const int _diametre, const int _longueur);
    int CalculerSection();
    int CalculerMasse();
protected:
    int diametre;
    float sectionRonde;
};

#endif // BARRERONDE_H
