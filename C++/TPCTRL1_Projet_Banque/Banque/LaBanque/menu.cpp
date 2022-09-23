#include "menu.h"

Menu::Menu(const string &_nom):
    nom(_nom),
    longueurMax(0),
    nbOptions(0),
    options(nullptr)
{
    ifstream fichierMenu(this->nom);
    if (fichierMenu.fail())
    {
        string message = " file not found !!";
        message = this->nom + message;
        Exception excep(404,message);
        throw (excep);
    }
    else
    {
        this->nbOptions = static_cast<int>(count(istreambuf_iterator<char>(fichierMenu),istreambuf_iterator<char>(),                                          '\n'));
        fichierMenu.seekg(0,ios::beg);
        int longueur;
        string item;
        this->options = new string[this->nbOptions];
        for( int i =0; i < this->nbOptions ; i++){
            getline(fichierMenu, item);
            longueur = static_cast<int>(item.length());
            if (longueur > longueurMax)
                longueurMax = longueur;
            if (longueur > 0)
                this->options[i] = item;
            else{
                this->nbOptions--;
                i--;
            }
        }
    }
}

Menu::~Menu()
{
    if (this->options != nullptr)
        delete  [] options;
}

int Menu::Afficher(const string &_nom)
{
    cout << " - " << _nom << " : " << endl <<endl;
    int choix;
    if (nbOptions == 0)
        choix = -1;
    else
    {
        cout << setfill('-');
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax+2) << "-+" << endl;
        cout << setfill(' ');
        for(int i =0; i < nbOptions; i++)
        {
            cout << "| " << i+1 << " | " << left << setw(longueurMax) << options[i]  << " |" << endl;
        }
        cout << setfill('-') << right;
        cout << "+-" << setw(4) << "-+-" << setw(longueurMax+2) << "-+" << endl;
        cout << setfill(' ');
        do
        {
            cout << "Votre choix : entre 1 et " << nbOptions  << endl;
            if(!(cin>>choix))
            {
                cin. clear();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                choix = -1;
            }
        }
        while (choix > (nbOptions));
    }
    for (int i = 3;i > 0; i--)
    {
        cout << "Sortie du menu \"" << _nom << "\" dans " << i << endl;
        usleep(300000);
    }
    return choix;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout << endl << "Appuyer sur la touche Entrée pour continuer ...";
    getline(cin,uneChaine);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

Exception::Exception(int _code, std::string _message):
    code(_code),
    message(_message)
{}

int Exception::ObtenirCodeErreur() const
{
    return code;
}

std::string Exception::ObtenirMessage() const
{
    return message;
}
