#include "equilibreuse.h"

Equilibreuse::Equilibreuse()
{
    leMoteur = new Moteur(laCarte);
    cout << "Constructeur Equilibreuse" << endl;
}
