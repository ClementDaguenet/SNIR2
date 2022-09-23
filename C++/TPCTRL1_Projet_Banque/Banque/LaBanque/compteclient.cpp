/**
 * @file compteclient.cpp
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#include "compteclient.h"

/**
 * @brief CompteClient::CompteClient
 * @details Constructeur de la classe CompteClient
 * @param _prenom le prenom du client
 * @param _nom le nom du client
 * @param _numero le numero de compte du client
 */

CompteClient::CompteClient(const string _prenom, const string _nom, const string _numero):
    prenom(_prenom),
    nom(_nom),
    numero(_numero)
{

}

/**
 * @brief CompteClient::CompteClient
 * @details Destructeur de la classe CompteClient
 */

CompteClient::~CompteClient()
{

}

/**
 * @brief CompteClient::CompteClient
 * @details Fonction d'identification de la classe CompteClient
 */

string CompteClient::Identification()
{
    cout << "Quel est votre prénom ? : ";
    cin >> prenom;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Quel est votre nom ? : ";
    cin >> nom;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Quel est votre numéro de compte ? : ";
    cin >> numero;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string client = "Espace Client de "+prenom+" "+nom+" n°"+numero;
    system("clear");
    return client;
}
