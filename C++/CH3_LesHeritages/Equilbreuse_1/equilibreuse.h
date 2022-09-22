#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include "moteur.h"
#include "mcculdaq.h"

class Equilibreuse
{
public:
    Equilibreuse();
private:
    MccUldaq laCarte;
    Moteur *leMoteur;
};

#endif // EQUILIBREUSE_H
