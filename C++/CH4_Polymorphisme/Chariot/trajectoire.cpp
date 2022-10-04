#include "trajectoire.h"

Trajectoire::Trajectoire(const int _nbEtapesMaxi):
    nbEtapesMaxi(_nbEtapesMaxi),
    prochaineEtape(0),
    depart(5,10)
{
    leParcours = new Element *[nbEtapesMaxi];
}

Trajectoire::~Trajectoire()
{
    delete [] leParcours;
}

bool Trajectoire::Ajouter(Element *_pElement)
{
    bool retour = true;
    if (prochaineEtape < nbEtapesMaxi )
    {
        leParcours[prochaineEtape++] = _pElement ;
    }
    else
    {
        retour = false;
    }
    return retour;
}

void Trajectoire::Afficher()
{
    Vecteur courant(0,0);
    courant = courant + depart;
    cout << "Trajectoire du chariot :" << endl << endl;
    double duree = 0;
    double longueur = 0;
    int num = 1;
    for (int i = 0; i < prochaineEtape ; i++)
    {
        if (i>0)
            num = leParcours[i-1]->getNumero() + 1;
        leParcours[i]->setNumero(num);
        leParcours[i]->Afficher();
        duree += leParcours[i]->ObtenirDuree();
        longueur += leParcours[i]->ObtenirLongueur();
        courant = courant + leParcours[i]->ObtenirVecteurArrivee();
        courant.Afficher();
    }
    cout << endl;
    cout << "Durée totale du parcours : " << duree << endl;
    cout << "Longueur totale du parcours : " << longueur << endl;
    cout << endl;
    cout << "Vecteur de départ : (" << depart.getX() << ", " << depart.getY() << ")" << endl;
    cout << "Vecteur d'arrivée : (" << courant.getX() << ", " << courant.getY() << ")" << endl;
}
