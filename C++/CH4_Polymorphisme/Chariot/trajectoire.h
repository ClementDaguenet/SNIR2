#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include "element.h"

class Trajectoire
{
public:
    Trajectoire(int const _nbEtapesMaxi);
    ~Trajectoire();
    bool Ajouter(Element *_pElement);
    void Afficher();
private:
    int nbEtapesMaxi;
    int prochaineEtape;
    Element **leParcours;
    Vecteur depart;
};

#endif // TRAJECTOIRE_H
