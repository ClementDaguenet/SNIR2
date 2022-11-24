#include "serveurbanque.h"

ServeurBanque::ServeurBanque(QObject *parent)
  : QTcpServer{parent}
{
  connect(this,&QTcpServer::newConnection,this,&ServeurBanque::onServeurBanqueNewConnection);
}

ServeurBanque::~ServeurBanque()
{

}

void ServeurBanque::Lancer()
{
  QMessageBox messageBox;
  if(!listen(QHostAddress::Any,8888))
    {
      messageBox.setText("Failed launch  : " + errorString());
    }
  messageBox.exec();
}

void ServeurBanque::Arreter()
{
  close();
}

void ServeurBanque::EnvoyerMessage(const QString _message, CompteClient *_client)
{
  quint16 taille = 0;
  QBuffer tampon;
  if(tampon.open(QIODevice::WriteOnly))
    {
      QDataStream sortie(&tampon);
      sortie << taille << _message;
      taille = tampon.size() - sizeof(taille);
      tampon.seek(0);
      sortie << taille;
      _client->write(tampon.buffer());
    }
}

void ServeurBanque::onServeurBanqueNewConnection()
{
  // récupération de socket de communication avec le client
  CompteClient *unClient = static_cast<CompteClient *>(nextPendingConnection());
  connect(unClient,&QTcpSocket::readyRead,this,&ServeurBanque::onCompteClientReadyRead);
  connect(unClient,&QTcpSocket::disconnected,this,&ServeurBanque::onCompteClientDisconnected);
  EnvoyerMessage("Numéro de compte ?", unClient);
  listeComptesClients.append(unClient);
}

void ServeurBanque::onCompteClientReadyRead()
{
  CompteClient *unClient = static_cast<CompteClient *>(sender());
  quint16 taille;
  QChar commande;
  float montant;
  int numCompte;
  if(unClient->bytesAvailable() >= static_cast<qint64>(sizeof(taille)))
    {
      QDataStream entree(unClient);
      entree >> taille;
      if (unClient->bytesAvailable() >= static_cast<qint64>(taille))
        {
          entree >> commande;
          switch(commande.toLatin1())
            {
            case 'N': // nouveau compte
              entree >> numCompte;
              unClient->DefinirNumCompte(numCompte);
              EnvoyerMessage("Bienvenue sur le compte " + QString::number(unClient->ObtenirNumCompte()), unClient);
              break;
            case 'S': // consulter solde
              EnvoyerMessage("Solde : " + QString::number(unClient->ObtenirSolde()), unClient);
              break;
            case 'D': // déposer
              entree >> montant;
              unClient->Deposer(montant);
              EnvoyerMessage("Nouveau solde : " + QString::number(unClient->ObtenirSolde()), unClient);
              break;
            case 'R': // retirer
              entree >> montant;
              if (unClient->Retirer(montant))
                {
                  EnvoyerMessage("Nouveau solde : " + QString::number(unClient->ObtenirSolde()), unClient);
                }
              else
                {
                  EnvoyerMessage("Solde insuffisant !", unClient);
                }
              break;
            }
        }
    }
}

void ServeurBanque::onCompteClientDisconnected()
{
  CompteClient *unClient = qobject_cast<CompteClient *>(sender());
  listeComptesClients.removeOne(unClient);
}
