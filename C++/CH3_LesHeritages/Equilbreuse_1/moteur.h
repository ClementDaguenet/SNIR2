#ifndef MOTEUR_H
#define MOTEUR_H

#include "libs.h"

class MccUldaq;

class Moteur
{
public:
    Moteur(MccUldaq & _laCarte, const int _numCanal = 5, const double _tensionMaxCommande = 4);
    ~Moteur();
    void FixerConsigne(const int _laConsigne);
private:
    int numCanal ;
    double tensionMaxCommande ;
    MccUldaq & laCarte;
};
#endif // MOTEUR_H
