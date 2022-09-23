/**
 * @file comptebancaire.cpp
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#include "comptebancaire.h"

/**
 * @brief CompteBancaire::CompteBancaire
 * @details Constructeur de la classe CompteBancaire
 * @param _solde le solde du compte
 */

CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{

}

/**
 * @brief CompteBancaire::CompteBancaire
 * @details Fonction d'ajout sur le compte de la classe CompteBancaire
 * @param _montant le montant à déposer
 */

void CompteBancaire::Deposer(float _montant)
{
    solde = solde + _montant;
}

/**
 * @brief CompteBancaire::CompteBancaire
 * @details Fonction de retrait sur le compte de la classe CompteBancaire
 * @param _montant le montant à retirer
 */

bool CompteBancaire::Retirer(float _montant)
{
    bool retour = false;
    if(solde - _montant < 0)
    {
        cout << "Vous rêvez, vous ne disposez pas d'autant d'argent !" << endl;
        cout << "Il vous manque : " << (solde-_montant)*-1 << " € sur votre compte" << endl;
    }
    else
    {
        solde -= _montant;
        retour = true;
    }
    return retour;
}

/**
 * @brief CompteBancaire::CompteBancaire
 * @details Fonction de consultation du solde de la classe CompteBancaire
 */

void CompteBancaire::ConsulterSolde()
{
    cout << "Votre solde est de " << solde << " €" << endl;
}
