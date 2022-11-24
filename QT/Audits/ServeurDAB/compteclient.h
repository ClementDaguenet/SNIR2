#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include <QTcpSocket>

class CompteClient : public QTcpSocket
{
  Q_OBJECT
public:
  explicit CompteClient(QObject *parent = nullptr);
  bool Retirer(float _montant);
  void Deposer(const float _montant);
  float ObtenirSolde();
  void DefinirNumCompte(const int _numCompte);
  int ObtenirNumCompte();

private:
  int numCompte;
  float solde;

};

#endif // COMPTECLIENT_H
