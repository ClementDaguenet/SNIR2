#include "barreronde.h"

BarreRonde::BarreRonde(const string _reference, const int _longueur, const float _densite, const int _diametre):
    Barre(_reference,_longueur,_densite),
    diametre(_diametre)
{
    // cout << "Constructeur BarreRonde" << endl;
}

BarreRonde::~BarreRonde()
{
    // cout << "Destructeur BarreRonde" << endl;
}

int BarreRonde::CalculerSection()
{
    sectionRonde = M_PI * pow(diametre,2) / 4;
    return sectionRonde;
}

void BarreRonde::AfficherCaracteristiques()
{
    Barre::AfficherCaracteristiques();
    cout << "Diamètre du rond : " << diametre << " cm" << endl;
    cout << "Poids de la barre : " << CalculerMasse() << " kg" << endl << endl;
}

double BarreRonde::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/1000);
    return masse;
}
