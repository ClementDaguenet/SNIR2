#include "magasin.h"

void Magasin::EntrerRouleau()
{
  int diametre;
  string reference;
  Rouleau *leRouleau;
  int rangee;
  int colonne;
  if (lesAlveolesLibres.Reserver(rangee,colonne) == true)
    {
      cout << "Référence du rouleau ? : ";
      cin >> reference;
      cout << "Diamètre du rouleau ? : ";
      cin >> diametre;
      cout << endl;
      cout << "Alvéole rangée n°" << rangee << ", colonne n°" << colonne << " réservée" << endl;
      leRouleau = new Rouleau(reference,diametre);
      leRouleau->AffecterAlveole(rangee,colonne);
      leStock.AjouterRouleau(*leRouleau);
      leChariot.DeplacerChariot(false, rangee, colonne);
    }
  else
    {
      cout << "Réservation impossible, place indisponible" << endl;
    }
}

void Magasin::SortirRouleaux()
{
  int rangee;
  int colonne;
  Rouleau leRouleau;
  Stock::POSITION_STOCK positionDebut;
  Stock::POSITION_STOCK positionRouleau;
  int nombre_rouleaux = leStock.RechercherSerie(positionDebut);
  cout << "Nombre : " << nombre_rouleaux << endl<< endl ;
  for (int indice = 0; indice < nombre_rouleaux; indice++)
    {
      (*positionDebut).ObtenirLocalisation(rangee,colonne);
      lesAlveolesLibres.Liberer(rangee,colonne);
      leStock.SortirRouleau(positionDebut++);
      leChariot.DeplacerChariot(true, rangee, colonne);
    }
  cout << "Ces rouleaux ont été sortis" << endl << endl;
}

void Magasin::Visualiser()
{
  cout << "Rouleaux du magasin : " << endl << endl;
  leStock.Visualiser();
  cout << endl << "Alvéoles libres : " << endl << endl;
  lesAlveolesLibres.Visualiser();
}
