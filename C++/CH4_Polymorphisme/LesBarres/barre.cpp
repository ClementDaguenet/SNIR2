#include "barre.h"


Barre::Barre(const string _reference, const int _longueur, const float _densite):
    reference(_reference),
    longueur(_longueur),
    densite(_densite)
{
    // cout << "Constructeur Barre" << endl;
}

Barre::~Barre()
{
    // cout << "Destructeur Barre" << endl;
}

void Barre::AfficherCaracteristiques()
{
    cout << "Référence : " << reference << endl;
    cout << "Longueur : " << longueur << " cm" << endl;
    cout << "Densité : " << densite << " g/cm3" << endl;
}
