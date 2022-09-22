#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    ifstream leFichier(nomDuFichier.c_str());
    if (!leFichier .is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        ofstream fichier("../01_Medailles/medailles_resultat.txt");
        if (!fichier .is_open())
            cerr << "Erreur lors de l'ouverture du fichier" << endl;
        else
        {
            string pays;
            int nbOr;
            int nbArgent;
            int nbBronze;
            fichier << "+" << setfill('-') << setw(18) << "+"  << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << setfill(' ') << endl;
            do
            {
                leFichier >> pays >> nbOr >> nbArgent >> nbBronze;
                if (leFichier.good())
                {
                    fichier << "|"
                            << " " << setw(16) << left << pays << "|"
                            << setw(7) << right << nbOr << " " << "|"
                            << setw(7) << right << nbArgent << " " << "|"
                            << setw(7) << right << nbBronze << " " << "|"
                            << endl;
                }
            }

        while (!leFichier.eof());
        fichier << "+" << setfill('-') << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << setfill(' ') << endl;
    } }
    return 0;
}
