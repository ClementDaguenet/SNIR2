#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "interfaceaccesbddbanque.h"
#include <QTcpSocket>

class CompteClient : public QTcpSocket
{
  Q_OBJECT
public:
  explicit CompteClient(QObject *parent = nullptr);
  bool Retirer(float _montant);
  void Deposer(const float _montant);
  float ObtenirSolde();
  bool DefinirNumCompte(const int _numCompte);
  int ObtenirNumCompte();
  void InitialiserBdd(const InterfaceAccesBddBanque *_accesBdd);

private:
  int numCompte;
  float solde;
  InterfaceAccesBddBanque *accesBdd;

};

#endif // COMPTECLIENT_H
