#include "pause.h"

Pause::Pause(const int _tempsAttente):
    Element(0),
    longueur(0),
    angle(0),
    tempsAttente(_tempsAttente)
{

}

void Pause::Afficher()
{
    cout << "(" << numero << ") Pause D = "  << tempsAttente << endl;
}

double Pause::ObtenirLongueur()
{
    return longueur;
}

double Pause::ObtenirDuree()
{
    return tempsAttente;
}

Vecteur Pause::ObtenirVecteurArrivee()
{
    Vecteur vecteurArrivee(longueur * cos(angle),longueur * sin(angle));
    return vecteurArrivee;
}
