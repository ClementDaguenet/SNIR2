#ifndef GUITARE_H
#define GUITARE_H

#include "instrumentacordes.h"

class Guitare : public InstrumentACordes
{
public:
    Guitare(const string _nom, const int _nbCordes, const string _modele);
    ~Guitare();
    void Afficher();
private:
    string modele;
};

#endif // GUITARE_H
