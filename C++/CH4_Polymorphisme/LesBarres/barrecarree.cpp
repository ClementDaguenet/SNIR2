#include "barrecarree.h"

BarreCarree::BarreCarree(const string _reference, const int _longueur,const float _densite, const int _largeur):
    Barre(_reference,_longueur,_densite),
    largeur(_largeur)
{
    // cout << "Constructeur BarreCarree" << endl;
}

BarreCarree::~BarreCarree()
{
    // cout << "Destructeur BarreCarree" << endl;
}

void BarreCarree::AfficherCaracteristiques()
{
    Barre::AfficherCaracteristiques();
    cout << "Côté du carré : " << largeur << " cm" << endl;
    cout << "Poids de la barre : " << CalculerMasse() << " kg" << endl << endl;
}

int BarreCarree::CalculerSection()
{
    sectionCarree = pow(largeur,2);
    return sectionCarree;
}

double BarreCarree::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/1000);
    return masse;
}
