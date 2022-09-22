/**
 * @file barrerectangle.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barrerectangle.h"

/**
 * @brief BarreRectangle::BarreRectangle
 * @details Constructeur de la classe BarreRectangle
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _hauteur la hauteur en m
 * @param _largeur la largeur en m
 */
BarreRectangle::BarreRectangle(const string _nom, const float _densite, const string _reference, const int _longueur, const int _hauteur, const int _largeur):
    Barre(_nom,_densite,_reference,_longueur),
    hauteur(_hauteur),
    largeur(_largeur)
{

}

int BarreRectangle::CalculerSection()
{
    sectionRectangle = largeur * hauteur;
    return sectionRectangle;
}

int BarreRectangle::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
