/**
 * @file main.cpp
 * @author Clément DAGUENET
 * @date 16/09/2022
 */
#include "barre.h"
#include "barreronde.h"
#include "barrerondecreuse.h"
#include "barrerectangle.h"
#include "barrerectanglecreuse.h"
#include "barrecarree.h"
#include "barrecarreecreuse.h"

/**
 * @brief main
 * @details Demande des différents paramètres selon les barres souhaitées
 * @return
 */
int main()
{
    // Densité : Cuivre 8,96 ; Diamant : 3,52 ; Aluminium : 2,7 ; Étain : 7,3 ; Or : 19,5 ; (g/cm3)

    cout << "Barres de mLego :" << endl;
    // nom, densite, reference, longueur, diametre
    BarreRonde uneBarreRonde("Ronde 1", 8.96, "#YBFG25", 1, 4);
    cout << "Section : " << uneBarreRonde.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreRonde.CalculerMasse() << " kg" << endl;

    // nom, densite, reference, longueur, diametre extérieur, diametre interieur ; -> diametre intérieur < diametre extérieur
    BarreRondeCreuse uneBarreRondeCreuse("Ronde Creuse 1", 8.96, "#YBFG26", 7, 4, 3);
    cout << "Section : " << uneBarreRondeCreuse.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreRondeCreuse.CalculerMasse() << " kg" << endl;

    // nom, densite, reference, longueur, hauteur, largeur
    BarreRectangle uneBarreRectangle("Rectangle 1", 8.96, "#FTHG15", 7, 6, 5);
    cout << "Section : " << uneBarreRectangle.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreRectangle.CalculerMasse() << " kg" << endl;

    // nom, densite, reference, longueur, hauteur interieur, largeur interieur, hauteur exterieur, largeur exterieur ; -> hauteur interieur < hauteur exterieur ; -> largeur interieur < largeur exterieur
    BarreRectangleCreuse uneBarreRectangleCreuse("Rectangle Creuse 1", 8.96, "#FTHG16", 7, 6, 5, 5, 4);
    cout << "Section : " << uneBarreRectangleCreuse.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreRectangleCreuse.CalculerMasse() << " kg" << endl;

    // nom, densite, reference, longueur, largeur
    BarreCarree uneBarreCarree("Carrée 1", 8.96, "#DGDT54", 7, 6);
    cout << "Section : " << uneBarreCarree.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreCarree.CalculerMasse() << " kg" << endl;

    // nom, densite, reference, longueur, largeur exterieur, largeur interieur ; -> largeur interieur < largeur exterieur
    BarreCarreeCreuse uneBarreCarreeCreuse("Carrée Creuse 1", 8.96, "#DGDT55", 7, 6, 5);
    cout << "Section : " << uneBarreCarreeCreuse.CalculerSection() << " mm2" << endl;
    cout << "Poids : " << uneBarreCarreeCreuse.CalculerMasse() << " kg" << endl;

    return 0;
}
