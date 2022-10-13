#include "barrecarree.h"
#include "barreronde.h"
#include "menu.h"
#include "catalogue.h"

int main()
{
    Menu menu("../LesBarres/menus/menu.txt");
    Catalogue leCatalogue(3);
    int choix;
    int sortie = 0;
    choix = menu.Afficher("Choix");
    string laReference;
    int laLongueur;
    float laDensite;
    int param1;
    while(sortie != 1)
    {
        switch(choix)
        {
        case CHOIX1:
            cout << "Vous avez choisi : Barre Carrée" << endl;
            system("clear");
            cout << "Référence de la barre : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, laReference);
            cout << "Longueur en cm : ";
            cin >> laLongueur;
            cout << "Densité en g/cm 3 : ";
            cin >> laDensite;
            cout << "Côté en cm : ";
            cin >> param1;
            leCatalogue.AjouterBarre(new BarreCarree(laReference,laLongueur,laDensite,param1));
            Menu::AttendreAppuiTouche();
            choix = menu.Afficher("Choix");
            break;
        case CHOIX2:
            cout << "Vous avez choisi : Barre Ronde" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("clear");
            cout << "Référence de la barre : ";
            getline(cin, laReference);
            cout << "Longueur en cm : ";
            cin >> laLongueur;
            cout << "Densité en g/cm 3 : ";
            cin >> laDensite;
            cout << "Diamètre en cm : ";
            cin >> param1;
            leCatalogue.AjouterBarre(new BarreRonde(laReference,laLongueur,laDensite,param1));
            Menu::AttendreAppuiTouche();
            choix = menu.Afficher("Choix");
            break;
        case CHOIX3:
            cout << "Vous avez choisi : Catalogue" << endl;
            system("clear");
            leCatalogue.AfficherCatalogue();
            Menu::AttendreAppuiTouche();
            choix = menu.Afficher("Choix");
            break;
        case QUITTER:
            cout << "Vous avez choisi : Quitter" << endl << endl;
            sortie=1;
            break;
        }
    }
    return 0;
}
