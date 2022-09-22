/**
 * @file barrerectanglecreuse.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barrerectanglecreuse.h"

/**
 * @brief BarreRectangleCreuse::BarreRectangleCreuse
 * @details Constructeur de la classe BarreRectangleCreuse
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _hauteurExterieur la hauteur extérieure en m
 * @param _largeurExterieur la largeur extérieure en m
 * @param _hauteurInterieur la hauteur intérieure en m
 * @param _largeurInterieur la largeur intérieure en m
 */
BarreRectangleCreuse::BarreRectangleCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _hauteurExterieur, const int _largeurExterieur, const int _hauteurInterieur, const int _largeurInterieur):
    BarreRectangle(_nom,_densite,_reference,_longueur,_hauteurExterieur,_largeurExterieur),
    hauteurInterieur(_hauteurInterieur),
    largeurInterieur(_largeurInterieur)
{

}

int BarreRectangleCreuse::CalculerSection()
{
    sectionRectangle = largeur * hauteur;
    float sectionRectangleCreuse = largeurInterieur * hauteurInterieur;
    return sectionRectangle - sectionRectangleCreuse;
}

int BarreRectangleCreuse::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
