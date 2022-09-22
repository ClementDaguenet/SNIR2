#ifndef INSTRUMENTDEMUSIQUE_H
#define INSTRUMENTDEMUSIQUE_H

#include "libs.h"

class InstrumentDeMusique
{
public:
    InstrumentDeMusique(const string _nom);
    ~InstrumentDeMusique();
    void Afficher();
private:
    string nom;
};

#endif // INSTRUMENTDEMUSIQUE_H
