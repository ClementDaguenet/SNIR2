/**
 * @file barrecarree.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRECARREE_H
#define BARRECARREE_H

#include "barre.h"

class BarreCarree : public Barre
{
public:
    BarreCarree(const string _nom, const float _densite, const string _reference, const int _longueur, const int _largeur);
    int CalculerSection();
    int CalculerMasse();
protected:
    int largeur;
    float sectionCarree;
};

#endif // BARRECARREE_H
