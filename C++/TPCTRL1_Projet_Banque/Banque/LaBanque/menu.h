#ifndef MENU_H
#define MENU_H

#include "libs.h"

enum MENU_BANCAIRE{
    CONSULTER_B = 1,
    DEPOT_B,
    RETRAIT_B,
    RETOUR_B
};
enum MENU_EPARGNE{
    CONSULTER_E = 1,
    DEPOT_E,
    RETRAIT_E,
    INTERETS_E,
    RETOUR_E
};
enum MENU_CLIENT{
//    OPEN_EPARGNE = 1,
    MANAGE_BANCAIRE = 1,
    MANAGE_EPARGNE,
    MODIFIER,
    QUITTER
};

class Menu
{
public:
    Menu(const string &_nom);
    ~Menu();
    int Afficher(const string &_nom);
    static void AttendreAppuiTouche();

private:
    /// nom du fichier à ouvrir pour créer le menu
    string nom;
    /// La plus grande longueur d'un item
    int longueurMax;
    /// Nombre d'items du menu
    int nbOptions;
    /// Pointeur sur tableau des items
    string *options;
};

class Exception
{
public:
    Exception(int _code, string _message);
    int ObtenirCodeErreur() const;
    string ObtenirMessage() const;

private:
    int code;
    string message;
};

#endif // MENU_H
