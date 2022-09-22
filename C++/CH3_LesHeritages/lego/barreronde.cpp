/**
 * @file barreronde.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barreronde.h"

/**
 * @brief BarreRonde::BarreRonde
 * @details Constructeur de la classe BarreRonde
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _diametre le diamètre en m
 */
BarreRonde::BarreRonde(const string _nom, const float _densite, const string _reference, const int _longueur, const int _diametre):
    Barre(_nom,_densite,_reference,_longueur),
    diametre(_diametre)
{

}

int BarreRonde::CalculerSection()
{
    sectionRonde = M_PI * pow(diametre,2) / 4;
    return sectionRonde;
}

int BarreRonde::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
