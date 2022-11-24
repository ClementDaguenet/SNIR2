#include "compteclient.h"

CompteClient::CompteClient(QObject *parent):
  QTcpSocket{parent}
{

}

bool CompteClient::Retirer(float _montant)
{
  bool retour = false;
  if (_montant < solde)
    {
      solde -= _montant;
      retour = true;
    }
  return retour;
}

void CompteClient::Deposer(const float _montant)
{
  solde += _montant;
}

float CompteClient::ObtenirSolde()
{
  return solde;
}

void CompteClient::DefinirNumCompte(const int _numCompte)
{
  numCompte = _numCompte;
}

int CompteClient::ObtenirNumCompte()
{
  return numCompte;
}
