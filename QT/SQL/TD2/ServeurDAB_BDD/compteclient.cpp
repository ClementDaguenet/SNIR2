#include "compteclient.h"

CompteClient::CompteClient(QObject *parent):
  QTcpSocket{parent}
{
  accesBdd = new InterfaceAccesBddBanque(this);
}

bool CompteClient::Retirer(float _montant)
{
  bool retour = false;
  if (_montant <= solde)
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

bool CompteClient::DefinirNumCompte(const int _numCompte)
{
  bool retour = true;
  if(accesBdd != nullptr)
    {
      if(!accesBdd->CompteExiste(_numCompte))
        retour = false;
      else
        solde = accesBdd->ObtenirSolde(_numCompte);
      numCompte = _numCompte;
    }
  return retour;
}

int CompteClient::ObtenirNumCompte()
{
  return numCompte;
}

void CompteClient::InitialiserBdd(const InterfaceAccesBddBanque *_accesBdd)
{

}
