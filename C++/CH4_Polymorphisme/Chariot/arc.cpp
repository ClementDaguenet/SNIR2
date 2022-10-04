#include "arc.h"

Arc::Arc(const int _vitesse, const double _rayon, const double _angleDebut, const double _angleFin):
    Element(_vitesse),
    rayon(_rayon),
    angleDebut(_angleDebut),
    angleFin(_angleFin)
{

}

void Arc::Afficher()
{
    cout << "(" << numero << ") Arc R = "  << setw(10) << left << rayon << "AD = " << setw(10) << left << angleDebut << "AF = " << setw(10) << left << angleFin << endl;
}

double Arc::ObtenirLongueur()
{
    return fabs(angleDebut - angleFin) * rayon;
}

double Arc::ObtenirDuree()
{
    return (fabs(angleDebut - angleFin) * rayon) / vitesse;
}

Vecteur Arc::ObtenirVecteurArrivee()
{
    Vecteur ptCentre(rayon * cos(angleDebut),rayon * sin(angleDebut));
    Vecteur ptArrivee(rayon * cos(angleFin),rayon * sin(angleFin));
    return (ptArrivee - ptCentre) ;
}
