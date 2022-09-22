
#include "instrumentacordes.h"


InstrumentACordes::InstrumentACordes(const string _nom, const int _nbCordes):
    InstrumentDeMusique(_nom),
    nbCordes(_nbCordes)
{
    cout << "C2" << endl << endl;
}

InstrumentACordes::~InstrumentACordes()
{
    cout << "D2" << endl;
}

void InstrumentACordes::Afficher()
{
    InstrumentDeMusique::Afficher();
    cout << "Nombre de cordes de l'instrument : " << nbCordes << endl;
}
