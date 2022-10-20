#include "menu.h"
#include "magasin.h"

int main()
{
  int sortie = 0;
  Menu menuMagasin("../MagasinDeRouleaux/menus/magasin.txt");
  int choix;
  string reference;
  Magasin leMagasin;
  choix = menuMagasin.Afficher("Magasin de Rouleaux");
  do
    {
      switch(choix)
        {
        case MENU_MAGASIN::AJOUTER:
          system("clear");
          cout << "Vous avez choisi : Entrer Rouleau" << endl;
          leMagasin.EntrerRouleau();
          Menu::AttendreAppuiTouche();
          choix = menuMagasin.Afficher("Magasin de Rouleaux");
          break;
        case MENU_MAGASIN::SORTIR:
          system("clear");
          cout << "Vous avez choisi : Sortir Serie" << endl;
          leMagasin.SortirRouleaux();
          Menu::AttendreAppuiTouche();
          choix = menuMagasin.Afficher("Magasin de Rouleaux");
          break;
        case MENU_MAGASIN::VISUALISER:
          system("clear");
          cout << "Vous avez choisi : Visualiser" << endl;
          leMagasin.Visualiser();
          Menu::AttendreAppuiTouche();
          choix = menuMagasin.Afficher("Magasin de Rouleaux");
          break;
        case MENU_MAGASIN::QUITTER:
          cout << "Vous avez choisi de quitter" << endl << endl;
          sortie = 1;
          break;
        }
    }
  while(sortie !=1 );
  return 0;
}
