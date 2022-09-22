#include "caissedebouteilles.h"


CaisseDeBouteilles::CaisseDeBouteilles(const int _largeur, const int _hauteur,const int _profondeur, const int _nbBouteilles, const int _contenance):
    Contenant(_largeur,_hauteur,_profondeur),
    nbBouteilles(_nbBouteilles),
    contenance(_contenance)
{
    cout << "Constructeur de la classe CaisseDeBouteilles" << endl;
}

CaisseDeBouteilles::~CaisseDeBouteilles()
{
    cout << "Destructeur de la classe CaisseDeBouteilles" << endl;
}

int CaisseDeBouteilles::CalculerVolume()
{
    return nbBouteilles * contenance;
}
