#ifndef MENU_H
#define MENU_H

#include "libs.h"

enum MENU
{
    CHOIX1 = 1,
    CHOIX2,
    CHOIX3,
    QUITTER
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
    static void AttendreAppuiTouche();
};

#endif // MENU_H
