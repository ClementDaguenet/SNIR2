/**
 * @file barreronde.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRERONDECREUSE_H
#define BARRERONDECREUSE_H

#include "barreronde.h"

class BarreRondeCreuse : public BarreRonde
{
public:
    BarreRondeCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _diametreExterieur, const int _diametreInterieur);
    int CalculerSection();
    int CalculerMasse();
protected:
    int diametreInterieur;
};

#endif // BARRERONDECREUSE_H
