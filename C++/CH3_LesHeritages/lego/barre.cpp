/**
 * @file barre.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barre.h"

/**
 * @brief Barre::Barre
 * @details Constructeur de la classe Barre
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 */
Barre::Barre(const string _nom, const float _densite, const string _reference, const int _longueur):
    nom(_nom),
    densite(_densite),
    reference(_reference),
    longueur(_longueur)
{
    AfficherCaracteristiques();
}

Barre::~Barre()
{

}

int Barre::AfficherCaracteristiques()
{
    cout << endl << "Barre " << nom << " :" << endl;
    cout << "Référence : " << reference << endl;
    cout << "Densité : " << densite << " g/cm3" << endl;
    cout << "Longueur : " << longueur << " m" << endl;
    return 0;
}
