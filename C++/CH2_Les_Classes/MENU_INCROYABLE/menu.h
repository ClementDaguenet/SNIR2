#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <unistd.h>

using namespace std;

enum MENU_CHOIX
{
    FICHIER = 1,
    EDITION = 2,
    AFFICHAGE = 3,
    RECHERCHER = 4,
    QUITTER = 5
};
enum MENU_FICHIER
{
    NOUVEAU = 1,
    OUVRIR = 2,
    ENREGISTRER = 3,
    IMPRIMER = 4,
    RETOUR1 = 5
};
enum MENU_EDITER
{
    ANNULER = 1,
    RETABLIR = 2,
    COPIER= 3,
    COLLER = 4,
    RETOUR2 = 5
};
enum MENU_AFFICHER
{
    BARRE_OUTILS = 1,
    BARRE_MENU = 2,
    AGRANDIR= 3,
    REDUIRE = 4,
    RETOUR3 = 5
};
enum MENU_RECHERCHER
{
    RECHERCHE = 1,
    SUIVANT = 2,
    PRECEDENT= 3,
    REMPLACER = 4,
    RETOUR4 = 5
};

class Menu
{
private:
    string nom;
    string * options;
    int nbOptions;
    unsigned long longueurMax;
public:
    Menu(const string &_nom);
    ~Menu();
    int Afficher(const string &_nom);
    static void AttendreAppuiTouche(const string &_nom);
};

#endif // MENU_H
