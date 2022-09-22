#include "instrumentdemusique.h"

InstrumentDeMusique::InstrumentDeMusique(const string _nom):
    nom(_nom)
{
    cout << "C1" << endl << endl;
}

InstrumentDeMusique::~InstrumentDeMusique()
{
    cout << "D1" << endl;
}

void InstrumentDeMusique::Afficher()
{
    cout << "Le nom de l'instrument est : " << nom << endl;
}
