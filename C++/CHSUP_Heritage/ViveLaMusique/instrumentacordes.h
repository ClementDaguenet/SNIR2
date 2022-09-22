#ifndef INSTRUMENTACORDES_H
#define INSTRUMENTACORDES_H

#include "instrumentdemusique.h"

class InstrumentACordes : public InstrumentDeMusique
{
public:
    InstrumentACordes(const string _nom, const int _nbCordes);
    ~InstrumentACordes();
    void Afficher();
private:
    int nbCordes;
};

#endif // INSTRUMENTACORDES_H
