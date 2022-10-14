#include "menu.h"
#include "stock.h"

int main()
{
  int choose;
  int sortie = 0;
  do
    {
      system("clear");
      cout << "(1 = Stock | 2 = AlveolesLibres | 3 = Rouleau | 4 = Quitter)" << endl << "Quel programme ? : "; // Demande du choix
      cin >> choose;
      if (choose == 1) // Choix du Programme de Stock
        {
          system("clear");
          // STOCK
          Menu menuStock("../AlveolesLibres/menus/stock.txt");
          int choixStock;
          int diametre;
          string reference;
          Rouleau *leRouleau;
          Stock leStock;
          Stock::POSITION_STOCK positionDebut;
          Stock::POSITION_STOCK positionRouleau;
          int nombre_rouleaux;
          int indice;
          choixStock = menuStock.Afficher("Stock");
          do
            {
              switch(choixStock)
                {
                case MENU_STOCK::AJOUTER:
                  system("clear");
                  cout << "Vous avez choisi : Ajouter un Rouleau" << endl;
                  cout << "Référence du rouleau ? : ";
                  cin >> reference;
                  cout << "Diamètre du rouleau ? : ";
                  cin >> diametre;
                  cout << endl;
                  leRouleau = new Rouleau(reference,diametre);
                  leStock.AjouterRouleau(*leRouleau);
                  Menu::AttendreAppuiTouche();
                  choixStock = menuStock.Afficher("Stock");
                  break;
                case MENU_STOCK::SORTIR:
                  system("clear");
                  cout << "Vous avez choisi : Sortir une Serie" << endl;
                  nombre_rouleaux = leStock.RechercherSerie(positionDebut);
                  cout << "Nombre : " << nombre_rouleaux << endl;
                  for (indice = 0; indice < nombre_rouleaux; indice++)
                    {
                      positionDebut->Visualiser();
                      leStock.SortirRouleau(positionDebut++);
                    }
                  cout << "Ces rouleaux ont été sortis" << endl << endl;
                  Menu::AttendreAppuiTouche();
                  choixStock = menuStock.Afficher("Stock");
                  break;
                case MENU_STOCK::VISUALISER_STOCK:
                  system("clear");
                  cout << "Vous avez choisi : Visualiser Stock" << endl;
                  leStock.Visualiser();
                  Menu::AttendreAppuiTouche();
                  choixStock = menuStock.Afficher("Stock");
                  break;
                case MENU_STOCK::QUITTER_STOCK:
                  cout << "Vous avez choisi de quitter" << endl << endl;
                  sortie = 1;
                  break;
                }
            }
          while(sortie !=1 );
        }
      else if(choose == 2) // Choix du Programme de AlveolesLibres
        {
          system("clear");
          // ALVEOLESLIBRES
          Menu menuAlveoles("../AlveolesLibres/menus/alveoles.txt");
          int choix;
          AlveolesLibres uneAlveole;
          choix = menuAlveoles.Afficher("Choix");
          do
            {
              switch(choix)
                {
                case MENU_ALVEOLE::RESERVER:
                  system("clear");
                  cout << "Vous avez choisi : Réserver Alvéoles" << endl;
                  int rangeeR;
                  int colonneR;
                  if (uneAlveole.Reserver(rangeeR,colonneR) == true)
                    {
                      cout << "Alvéole rangée n°" << rangeeR << ", colonne n°" << colonneR << " réservée" << endl;
                    }
                  else
                    {
                      cout << "Réservation impossible, place indisponible" << endl;
                    }
                  Menu::AttendreAppuiTouche();
                  choix = menuAlveoles.Afficher("Choix");
                  break;
                case MENU_ALVEOLE::LIBERER:
                  system("clear");
                  cout << "Vous avez choisi : Libérer Alvéoles" << endl;
                  int rangeeL;
                  int colonneL;
                  cout << "Rangée à libérer ? : ";
                  cin >> rangeeL;
                  cout << "Colonne à libérer ? : ";
                  cin >> colonneL;
                  if(uneAlveole.Liberer(rangeeL,colonneL) == true)
                    {
                      cout << "Alvéole rangée n°" << rangeeL << ", colonne n°" << colonneL << " libérée" << endl;
                    }
                  else
                    {
                      cout << "Libération impossible, alvéoles pleines" << endl;
                    }
                  Menu::AttendreAppuiTouche();
                  choix = menuAlveoles.Afficher("Choix");
                  break;
                case MENU_ALVEOLE::VISUALISER:
                  system("clear");
                  cout << "Vous avez choisi : Visualiser Alvéoles" << endl << "Alvéoles libres :" << endl << endl;
                  uneAlveole.Visualiser();
                  Menu::AttendreAppuiTouche();
                  choix = menuAlveoles.Afficher("Choix");
                  break;
                case MENU_ALVEOLE::QUITTER:
                  cout << "Vous avez choisi de quitter" << endl << endl;
                  sortie=1;
                  break;
                }
            }
          while(sortie!=1);
        }
      else if (choose == 3) // Choix du Programme de Rouleau
        {
          system("clear");
          // ROULEAU
          Rouleau r1("A-320", 200);
          r1.AffecterAlveole(4,5);
          Rouleau r2("B-747", 150);
          r2.AffecterAlveole(2,3);
          int rang;
          int colo;
          r1.Visualiser();
          r2.Visualiser();
          r1.ObtenirLocalisation(rang,colo);
          cout << "r1 est en " << rang << " - " << colo << endl;
          r2.ObtenirLocalisation(rang,colo);
          cout << "r2 est en " << rang << " - " << colo << endl;
          if (r1<r2)
            {
              cout << endl << "r1 est supérieur ou égal à r2" << endl << endl;
              cout << "La différence entre les diamètres est de : " << r1-r2 << endl;
            }
          else
            {
              cout << "r1 est inférieur à r2" << endl;
            }
          sleep(10);
        }
      else if (choose == 4) // Choix de quitter
        {
          cout << "À bientôt !" << endl;
          sortie = 1;
        }
      else
        {
          cout << "Choisis tes mots avec plus de discernement" << endl << endl;
          sleep(2);
          system("clear");
        }
    }
  while (sortie != 1);
  return 0;
}
