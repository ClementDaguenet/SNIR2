#ifndef MENU_H
#define MENU_H

#include "libs.h"

enum MENU_ALVEOLE{
  RESERVER = 1,
  LIBERER,
  VISUALISER,
  QUITTER
};

enum MENU_STOCK{
  AJOUTER = 1,
  SORTIR,
  VISUALISER_STOCK,
  QUITTER_STOCK
};

class Menu
{
public:
  Menu(const string &_nom);
  ~Menu();
  int Afficher(const string &_nom);
  static void AttendreAppuiTouche();
private:
  /// Nom du fichier à ouvrir pour créer le menu
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
