#include <iostream>
#include "ipv4.h"

using namespace std;

void AfficherTableau(unsigned char *tab);

int main()
{
    unsigned char adresse[4] = {192,168,1,1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char premiere_adresse[4];
    unsigned char derniere_adresse[4];
    int nb_machines;

    IPv4 uneAdresse(adresse , 24);
    cout << "Adresse IPv4 : ";
    AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque);
    cout << "Masque : ";
    AfficherTableau(masque);
    uneAdresse.ObtenirAdresseReseau(reseau);
    cout << "Réseau : ";
    AfficherTableau(reseau);
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    cout << "Diffusion : ";
    AfficherTableau(diffusion);
    uneAdresse.ObtenirPremiereAdresse(premiere_adresse);
    cout << "Première Adresse : ";
    AfficherTableau(premiere_adresse);
    uneAdresse.ObtenirDerniereAdresse(derniere_adresse);
    cout << "Dernière Adresse : ";
    AfficherTableau(derniere_adresse);
    nb_machines = uneAdresse.ObtenirNombreDeMachines();
    cout << "Nombre de Machines : " << nb_machines << endl;
    return 0;
}

void AfficherTableau(unsigned char *tab)
{
    for(int indice=0 ; indice < 4 ; indice ++)
    {
        cout << static_cast<int> (tab[indice]);
        if(indice < 3)
            cout << "." ;
    }
    cout << endl;
}
