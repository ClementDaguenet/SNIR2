#ifndef INTERFACEACCESBDDBANQUE_H
#define INTERFACEACCESBDDBANQUE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class InterfaceAccesBddBanque : public QObject
{
  Q_OBJECT
public:
  explicit InterfaceAccesBddBanque(QObject *parent = nullptr);
  float ObtenirSolde(const int _numCompte);
  void MettreAJourLeSolde(const int _numCompte, const float _nouveauSolde);
  bool CompteExiste(const int _numCompte);

private:
  QSqlDatabase bdd;

signals:

};

#endif // INTERFACEACCESBDDBANQUE_H
