/**
 * @file compteepargne.cpp
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#include "compteepargne.h"

/**
 * @brief CompteEpargne::CompteEpargne
 * @details Constructeur de la classe CompteEpargne
 * @param _tauxInterets le taux d'intérêts actuel
 * @param _solde le solde du compte
 */

CompteEpargne::CompteEpargne(const float _tauxInterets, const float _solde):
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{

}

/**
 * @brief CompteEpargne::CompteEpargne
 * @details Fonctiond de calcul d'interets de la classe CompteEpargne
 */

float CompteEpargne::CalculerInterets()
{
    double interets = solde * tauxInterets - solde;
    solde += interets;
    return interets;
}

/**
 * @brief CompteEpargne::CompteEpargne
 * @details Constructeur de changement de taux de la classe CompteEpargne
 * @param _newTaux le nouveau taux
 */

void CompteEpargne::ModifierTaux(const float _newTaux)
{
    tauxInterets = _newTaux;
}


