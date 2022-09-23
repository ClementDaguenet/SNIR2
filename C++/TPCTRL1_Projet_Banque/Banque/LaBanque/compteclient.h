/**
 * @file compteclient.h
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "compteepargne.h"

class CompteClient
{
public:
    CompteClient(const string _prenom = "Albert", const string _nom = "DUPONT", const string _numero = "1");
    ~CompteClient();
    string Identification();
    void OuvrirCompteEpargne();
private:
    string prenom;
    string nom;
    string numero;
};

#endif // COMPTECLIENT_H
