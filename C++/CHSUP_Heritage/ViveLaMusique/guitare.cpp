#include "guitare.h"


Guitare::Guitare(const string _nom, const int _nbCordes, const string _modele):
    InstrumentACordes(_nom,_nbCordes),
    modele(_modele)
{
    cout << "C3" << endl << endl;
}

Guitare::~Guitare()
{
    cout << "D3" << endl;
}

void Guitare::Afficher()
{
    InstrumentDeMusique::Afficher();
    InstrumentACordes::Afficher();
    cout << "Modèle de l'instrument : " << modele << endl;
}
