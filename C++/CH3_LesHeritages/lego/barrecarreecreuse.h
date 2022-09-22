/**
 * @file barrecarreecreuse.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRECARREECREUSE_H
#define BARRECARREECREUSE_H

#include "barrecarree.h"

class BarreCarreeCreuse : public BarreCarree
{
public:
    BarreCarreeCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _largeurExterieur, const int _largeurInterieur);
    int CalculerSection();
    int CalculerMasse();
protected:
    int largeurInterieur;
};

#endif // BARRECARREECREUSE_H
