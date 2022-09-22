/**
 * @file barrecarree.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barrecarree.h"

/**
 * @brief BarreCarree::BarreCarree
 * @details Constructeur de la classe BarreCarree
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _largeur la largeur en m
 */
BarreCarree::BarreCarree(const string _nom, const float _densite, const string _reference, const int _longueur, const int _largeur):
    Barre(_nom,_densite,_reference,_longueur),
    largeur(_largeur)
{

}

int BarreCarree::CalculerSection()
{
    sectionCarree = pow(largeur,2);
    return sectionCarree;
}

int BarreCarree::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
