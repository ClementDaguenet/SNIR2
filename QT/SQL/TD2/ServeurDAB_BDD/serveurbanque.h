#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H

#include "compteclient.h"
#include "interfaceaccesbddbanque.h"
#include <QTcpServer>
#include <QMessageBox>
#include <QBuffer>
#include <QSettings>

class ServeurBanque : public QTcpServer
{
  Q_OBJECT
public:
  explicit ServeurBanque(QObject *parent = nullptr);
  ~ServeurBanque();
  void Lancer();
  void Arreter();
  void EnvoyerMessage(const QString _message, CompteClient *_client);

private slots:
  void onServeurBanqueNewConnection();
  void onCompteClientReadyRead();
  void onCompteClientDisconnected();

private:
  QList <CompteClient *>listeComptesClients;
  InterfaceAccesBddBanque *accesBdd;

};

#endif // SERVEURBANQUE_H
