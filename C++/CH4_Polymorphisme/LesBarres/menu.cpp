#include "menu.h"

Menu::Menu(const string &_nom)
    :nom(_nom),
      longueurMax(0)
{
    ifstream fichierMenu(nom);
    if (!fichierMenu.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        nbOptions = static_cast<int>(count(istreambuf_iterator<char>(fichierMenu),istreambuf_iterator<char>(),'\n'));
        fichierMenu.seekg(0,ios::beg);
        options = new string [nbOptions];
        for (int indice = 0; indice < nbOptions; indice++)
        {
            getline(fichierMenu,options[indice]);
            if (options[indice].length() > longueurMax)
            {
                longueurMax = options[indice].length();
            }
        }
    }
}

Menu::~Menu()
{
    if (options != nullptr) {
        delete[] options;
    }
}

int Menu::Afficher(const string &_nom)
{
    cout << " - Menu de " << _nom << " : " << endl <<endl;
    cout << right << "+" << setw(6) << setfill('-') << "+" << setw(longueurMax+3) << "+" << endl; // Affichage du menu
    for (int indice = 0; indice < nbOptions; indice++)
    {
        cout << "|" << setw(3) << setfill(' ')
             << right << indice+1 << setw(4) << "| " << setw(longueurMax)
             << left << options[indice] << " |" << endl;
    }
    cout << right << "+" << setw(6) << setfill('-') << "+" << setw(longueurMax+3) << "+" << endl << endl;

    int choix; // Demande du choix
    cout << "Entrez un nombre entre " << 1 << " et " << nbOptions << " : ";

    if(!(cin >> choix))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        choix = -1;
    }
    for (int i = 3;i > 0; i--){
        cout << "Sortie du menu \"" << _nom << "\" dans " << i << endl;
        usleep(500000);
    }
    return choix;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour retourner au menu ";
    getline(cin,uneChaine);
    cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    system("clear");
}
