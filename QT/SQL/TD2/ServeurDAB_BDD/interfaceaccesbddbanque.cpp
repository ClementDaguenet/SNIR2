#include "interfaceaccesbddbanque.h"

InterfaceAccesBddBanque::InterfaceAccesBddBanque(QObject *parent)
  : QObject{parent}
{

}

float InterfaceAccesBddBanque::ObtenirSolde(const int _numCompte)
{

  return 0;
}

void InterfaceAccesBddBanque::MettreAJourLeSolde(const int _numCompte, const float _nouveauSolde)
{

}

bool InterfaceAccesBddBanque::CompteExiste(const int _numCompte)
{
  QSqlQuery requete;
  bool existe = false;
  // recherche si le compte existe
  if (requete.size() != 0) // si le compte existe on passe existe a vrai
    existe=true;
  return existe;
}
