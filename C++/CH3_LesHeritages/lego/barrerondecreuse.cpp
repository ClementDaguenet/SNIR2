/**
 * @file barrerondecreuse.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barrerondecreuse.h"

/**
 * @brief BarreRonde::BarreRonde
 * @details Constructeur de la classe BarreRonde
 * @param _nom le nom de la barre
 * @param _densite la densite en g/cm3
 * @param _reference la reference de la barre
 * @param _longueur la longueur en m
 * @param _diametreExterieur le diamètre extérieur en m
 * @param _diametreInterieur le diamètre intérieur en m
 */
BarreRondeCreuse::BarreRondeCreuse(const string _nom, const float _densite, const string _reference, const int _longueur, const int _diametreExterieur, const int _diametreInterieur):
    BarreRonde(_nom,_densite,_reference,_longueur,_diametreExterieur),
    diametreInterieur(_diametreInterieur)
{

}

int BarreRondeCreuse::CalculerSection()
{
    sectionRonde = M_PI * pow(diametre,2) / 4;
    float sectionRondeCreuse = M_PI * pow(diametreInterieur,2) / 4;
    return sectionRonde - sectionRondeCreuse;
}

int BarreRondeCreuse::CalculerMasse()
{
    float masse = longueur * CalculerSection() * (densite/100);
    return masse;
}
