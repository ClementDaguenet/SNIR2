/**
 * @file barrerectanglecreuse.h
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#ifndef BARRERECTANGLECREUSE_H
#define BARRERECTANGLECREUSE_H

#include "barrerectangle.h"

class BarreRectangleCreuse : public BarreRectangle
{
public:
    BarreRectangleCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _hauteurExterieur, const int _largeurExterieur, const int _hauteurInterieur, const int _largeurInterieur);
    int CalculerSection();
    int CalculerMasse();
protected:
    int hauteurInterieur;
    int largeurInterieur;
};

#endif // BARRERECTANGLECREUSE_H
