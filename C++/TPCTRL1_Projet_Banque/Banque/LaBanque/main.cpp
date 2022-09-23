/**
 * @file main.cpp
 * @author Clément DAGUENET
 * @date 23/09/2022
 */
#include "menu.h"
#include "compteclient.h"

int main()
{
    /**
     * @details Initialisation des paramètres et des chemins des menus
     */
    CompteClient leCompteClient;
    Menu menuClient("../LaBanque/menus/client.txt");
    CompteBancaire leCompteBancaire(1000);
    Menu menuBancaire("../LaBanque/menus/compteBancaire.txt");
    CompteEpargne leCompteEpargne(1.02);
    Menu menuEpargne("../LaBanque/menus/compteEpargne.txt");
    int choix;
    int sortie = 0;
    float montant;
    float taux;
    string nom;
    string numero;
    string client = leCompteClient.Identification();
    choix = menuClient.Afficher(client);
    do
    {
        /**
         * @brief Affichage premier menu
         * @details Choix à partir du premier menu
         */
        switch(choix)
        {
        case MENU_CLIENT::MANAGE_BANCAIRE:
            cout << "Vous avez choisi : Gerer le compte Bancaire" << endl;
            system("clear");
            choix = menuBancaire.Afficher("Compte Bancaire");
            switch(choix) // TEST COMPTE BANCAIRE
            {
            /**
             * @brief Gérer compte Bancaire
             * @details Si choix du compte bancaire
             */
            case MENU_BANCAIRE::CONSULTER_B:
                cout << "Vous avez choisi : Consulter le solde" << endl;
                system("clear");
                leCompteBancaire.ConsulterSolde();
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_BANCAIRE::DEPOT_B:
                cout << "Vous avez choisi : Effectuer un depot" << endl;
                system("clear");
                cout << "Combien voulez vous déposer (en €) ? : ";
                cin >> montant;
                leCompteBancaire.Deposer(montant);
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_BANCAIRE::RETRAIT_B:
                cout << "Vous avez choisi : Effectuer un retrait" << endl;
                system("clear");
                cout << "Combien voulez vous retirer (en €) ? : ";
                cin >> montant;
                leCompteBancaire.Retirer(montant);
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_BANCAIRE::RETOUR_B:
                cout << "Vous avez choisi : Retour" << endl << endl;
                system("clear");
                choix = menuClient.Afficher(client);
                // sortie = 1;
                break;
            }
            break;
        case MENU_CLIENT::MANAGE_EPARGNE:
            cout << "Vous avez choisi : Gerer le compte Epargne" << endl;
            system("clear");
            choix = menuEpargne.Afficher("Compte Epargne");
            switch(choix) // TEST COMPTE EPARGNE
            {
            /**
             * @brief Gérer compte Epargne
             * @details Si choix du compte épargne
             */
            case MENU_EPARGNE::CONSULTER_E:
                cout << "Vous avez choisi : Consulter le solde" << endl;
                system("clear");
                leCompteEpargne.ConsulterSolde();
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_EPARGNE::DEPOT_E:
                cout << "Vous avez choisi : Effectuer un depot" << endl;
                system("clear");
                cout << "Combien voulez vous déposer (en €) ? : ";
                cin >> montant;
                leCompteEpargne.Deposer(montant);
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_EPARGNE::RETRAIT_E:
                cout << "Vous avez choisi : Effectuer un retrait" << endl;
                system("clear");
                cout << "Combien voulez vous retirer (en €) ? : ";
                cin >> montant;
                leCompteEpargne.Retirer(montant);
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_EPARGNE::INTERETS_E:
                cout << "Vous avez choisi : Calculer les interets" << endl;
                system("clear");
                cout << "Vos intérêts sont de : " << leCompteEpargne.CalculerInterets() << " €" << endl;
                Menu::AttendreAppuiTouche();
                choix = menuClient.Afficher(client);
                break;
            case MENU_EPARGNE::RETOUR_E:
                cout << "Vous avez choisi : Retour" << endl << endl;
                system("clear");
                choix = menuClient.Afficher(client);
                // sortie = 1;
                break;
            }
            break;
        case MENU_CLIENT::MODIFIER:
            /**
             * @brief Modifier le taux
             * @details Si choix de modification du taux
             */
            cout << "Vous avez choisi : Modifier le taux" << endl;
            system("clear");
            cout << "Quel est le taux cette année ? (entre 1.01 et 1.99) : ";
            cin >> taux;
            leCompteEpargne.ModifierTaux(taux);
            Menu::AttendreAppuiTouche();
            choix = menuClient.Afficher(client);
            break;
        case MENU_CLIENT::QUITTER:
            /**
             * @brief Quitter
             * @details Si choix de quitter
             */
            cout << "Vous avez choisi de quitter" << endl << endl;
            sortie=1;
            break;
        }
    }while(sortie!=1);
    return 0;
}
