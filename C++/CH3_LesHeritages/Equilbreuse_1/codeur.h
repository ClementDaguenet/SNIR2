#ifndef CODEUR_H
#define CODEUR_H

#include "libs.h"
class MccUldaq;

class Codeur
{
public:
    Codeur(const MccUldaq & _laCarte);
    int ObtenirVitesse();
};

#endif // CODEUR_H
