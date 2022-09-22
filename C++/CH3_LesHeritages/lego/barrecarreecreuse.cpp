/**
 * @file barrecarreecreuse.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barrecarreecreuse.h"

/**
 * @brief BarreCarreeCreuse::BarreCarreeCreuse
 * @details Constructeur de la classe BarreCarreeCreuse
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _largeurExterieur la largeur extérieure en m
 * @param _largeurInterieur la largeur intérieure en m
 */
BarreCarreeCreuse::BarreCarreeCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _largeurExterieur, const int _largeurInterieur):
    BarreCarree(_nom,_densite,_reference,_longueur,_largeurExterieur),
    largeurInterieur(_largeurInterieur)
{

}

int BarreCarreeCreuse::CalculerSection()
{
    sectionCarree = pow(largeur,2);
    float sectionCarreeCreuse = pow(largeurInterieur,2);
    return sectionCarree - sectionCarreeCreuse;
}

int BarreCarreeCreuse::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
