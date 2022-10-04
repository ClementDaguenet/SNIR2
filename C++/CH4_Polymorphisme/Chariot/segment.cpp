#include "segment.h"

Segment::Segment(const int _vitesse, const double _longueur, const double _angle):
    Element(_vitesse),
    longueur(_longueur),
    angle(_angle)
{

}

void Segment::Afficher()
{
    cout << "(" << numero << ") Segment L = "  << setw(10) << left << longueur << "A = " << setw(10) << left << angle << "V = " << vitesse << endl;
}

double Segment::ObtenirLongueur()
{
    return longueur;
}

double Segment::ObtenirDuree()
{
    return longueur / vitesse;
}

Vecteur Segment::ObtenirVecteurArrivee()
{
    Vecteur vecteurArrivee(longueur * cos(angle),longueur * sin(angle));
    return vecteurArrivee;
}
