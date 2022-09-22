#include <iostream>
#include "menu.h"

using namespace std;

//string tabChoix[5]={"Fichier","Edition","Affichage","Rechercher","Quitter"};
//string tabFichier[5]={"Nouveau","Ouvrir","Enregistrer","Imprimer","Retour"};
//string tabEditer[5]={"Annuler","Retablir","Copier","Coller","Retour"};
//string tabAfficher[5]={"Barre d'outils","Barre de menu","Agrandir","Reduire","Retour"};
//string tabRechercher[5]={"Rechercher","Suivant","Precedent","Remplacer","Retour"};


int main()
{
    string chemin = "../menu/menus/";
    Menu menuChoix(chemin+"choix.txt");
    Menu menuFichier(chemin+"fichier.txt");
    Menu menuEditer(chemin+"editer.txt");
    Menu menuAfficher(chemin+"afficher.txt");
    Menu menuRechercher(chemin+"rechercher.txt");
    int choix;
    int sortie = 0;
    choix = menuChoix.Afficher("Choix");
    while(sortie != 1)
    {
        switch (choix)
        {
        case MENU_CHOIX::FICHIER:
            cout << "Vous avez choisi : Fichier" << endl;
//            Menu::AttendreAppuiTouche();
            choix = menuFichier.Afficher("Fichier");
            switch (choix)
            {
            case MENU_FICHIER::NOUVEAU:
                cout << "Vous avez choisi : Nouveau" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_FICHIER::OUVRIR:
                cout << "Vous avez choisi : Ouvrir" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_FICHIER::ENREGISTRER:
                cout << "Vous avez choisi : Enregistrer" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_FICHIER::IMPRIMER:
                cout << "Vous avez choisi : Imprimer" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_FICHIER::RETOUR1:
                cout << "Vous avez choisi : Retour" << endl;
                Menu::AttendreAppuiTouche();
                choix = menuChoix.Afficher("Choix");
                break;
            }
            break;
        case MENU_CHOIX::EDITION:
            cout << "Vous avez choisi : Edition" << endl;
            Menu::AttendreAppuiTouche();
            choix = menuEditer.Afficher("Edition");
            switch (choix)
            {
            case MENU_EDITER::ANNULER:
                cout << "Vous avez choisi : Annuler" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_EDITER::RETABLIR:
                cout << "Vous avez choisi : Retablir" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_EDITER::COPIER:
                cout << "Vous avez choisi : Copier" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_EDITER::COLLER:
                cout << "Vous avez choisi : Coller" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_EDITER::RETOUR2:
                cout << "Vous avez choisi : Retour" << endl;
                Menu::AttendreAppuiTouche();
                choix = menuChoix.Afficher("Choix");
                break;
            }
            break;
        case MENU_CHOIX::AFFICHAGE:
            cout << "Vous avez choisi : Affichage" << endl;
            Menu::AttendreAppuiTouche();
            choix = menuAfficher.Afficher("Affichage");
            switch (choix)
            {
            case MENU_AFFICHER::BARRE_OUTILS:
                cout << "Vous avez choisi : Barre d'outils" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_AFFICHER::BARRE_MENU:
                cout << "Vous avez choisi : Barre menu" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_AFFICHER::AGRANDIR:
                cout << "Vous avez choisi : Agrandir" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_AFFICHER::REDUIRE:
                cout << "Vous avez choisi : Reduire" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_AFFICHER::RETOUR3:
                cout << "Vous avez choisi : Retour" << endl;
                Menu::AttendreAppuiTouche();
                choix = menuChoix.Afficher("Choix");
                break;
            }
            break;
        case MENU_CHOIX::RECHERCHER:
            cout << "Vous avez choisi : Rechercher" << endl;
            Menu::AttendreAppuiTouche();
            choix = menuRechercher.Afficher("Rechercher");
            switch (choix)
            {
            case MENU_RECHERCHER::RECHERCHE:
                cout << "Vous avez choisi : Rechercher" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_RECHERCHER::SUIVANT:
                cout << "Vous avez choisi : Suivant" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_RECHERCHER::PRECEDENT:
                cout << "Vous avez choisi : Precedent" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_RECHERCHER::REMPLACER:
                cout << "Vous avez choisi : Remplacer" << endl;
                Menu::AttendreAppuiTouche();
                sortie=1;
                break;
            case MENU_RECHERCHER::RETOUR4:
                cout << "Vous avez choisi : Retour" << endl;
                Menu::AttendreAppuiTouche();
                choix = menuChoix.Afficher("Choix");
                break;
            }
            break;
        case MENU_CHOIX::QUITTER:
            cout << "Vous avez choisi : Quitter" << endl;
            sortie=1;
            break;
        }
    }
    return 0;
}
