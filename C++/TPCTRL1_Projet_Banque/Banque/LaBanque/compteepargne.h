/**
 * @file compteepargne.h
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "comptebancaire.h"

class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _tauxInterets = 1.02, const float _solde = 0);
    float CalculerInterets();
    void ModifierTaux(const float _newTaux);
private:
    float tauxInterets;
};

#endif // COMPTEEPARGNE_H
