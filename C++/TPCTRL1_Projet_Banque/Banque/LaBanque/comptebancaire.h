/**
 * @file comptebancaire.h
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include "libs.h"

class CompteBancaire
{
public:
    CompteBancaire(const float _solde = 0);
    void Deposer(float _montant);
    bool Retirer(float _montant);
    void ConsulterSolde();
protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
