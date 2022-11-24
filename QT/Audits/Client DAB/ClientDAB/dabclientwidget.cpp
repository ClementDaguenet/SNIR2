#include "dabclientwidget.h"
#include "ui_dabclientwidget.h"

DabClientWidget::DabClientWidget(QWidget *parent):
  QWidget(parent),
  ui(new Ui::DabClientWidget)
{
  ui->setupUi(this);
  setWindowTitle("Distributeur Automatique de Billets");
  ui->groupBox_Operations->setDisabled(true);
  // association signal/slot pour socketClientBanque
  connect(&socketClientBanque, &QTcpSocket::connected,this,&DabClientWidget::onQTcpSocketConnected);
  connect(&socketClientBanque, &QTcpSocket::disconnected,this,&DabClientWidget::onQTcpSocketDisconnected);
  connect(&socketClientBanque, &QTcpSocket::readyRead,this,&DabClientWidget::onQTcpSocketReadyRead);
  connect(&socketClientBanque, &QTcpSocket::stateChanged,this,&DabClientWidget::onQTcpSocketStateChanged);
  connect(&socketClientBanque, &QTcpSocket::errorOccurred,this,&DabClientWidget::onQTcpSocketErrorOccurred);
  connect(&socketClientBanque, &QTcpSocket::hostFound,this,&DabClientWidget::onQTcpSocketHostFound);
  connect(&socketClientBanque, &QTcpSocket::aboutToClose,this,&DabClientWidget::onQTcpSocketAboutToClose);
  connect(&socketClientBanque, &QTcpSocket::bytesWritten,this,&DabClientWidget::onQTcpSocketBytesWritten);
}

DabClientWidget::~DabClientWidget()
{
  delete ui;
}

void DabClientWidget::on_pushButton_Connexion_clicked()
{
  if(ui->pushButton_Connexion->text()=="Déconnexion")
    {
      socketClientBanque.disconnectFromHost();
    }
  else if(ui->pushButton_Connexion->text()=="Connexion")
    {
      socketClientBanque.connectToHost(ui->lineEdit_IP->text(),ui->lineEdit_Port->text().toInt());
    }
}

void DabClientWidget::on_pushButton_Numero_clicked()
{
  quint16 taille = 0;
  QChar commande = 'N';
  int numCompte = ui->lineEdit_Numero->text().toInt();
  QBuffer tampon;
  if(tampon.open(QIODevice::WriteOnly))
    {
      QDataStream sortie(&tampon);
      sortie << taille << commande << numCompte ;
      taille = tampon.size() - sizeof(taille);
      tampon.seek(0);
      sortie << taille;
      socketClientBanque.write(tampon.buffer());
    }
}

void DabClientWidget::on_pushButton_Envoi_clicked()
{
  quint16 taille = 0;
  QChar commande = 'N';
  float montant = ui->lineEdit_Montant->text().toFloat();
  QBuffer tampon;
  if(ui->radioButton_Solde->isChecked())
    {
      commande = 'S';
      if(tampon.open(QIODevice::WriteOnly))
        {
          QDataStream sortie(&tampon);
          sortie << taille << commande;
          taille = tampon.size() - sizeof(taille);
          tampon.seek(0);
          sortie << taille;
          socketClientBanque.write(tampon.buffer());
        }
    }
  else if(ui->radioButton_Depot->isChecked())
    {
      commande = 'D';
      if(tampon.open(QIODevice::WriteOnly))
        {
          QDataStream sortie(&tampon);
          sortie << taille << commande << montant ;
          taille = tampon.size() - sizeof(taille);
          tampon.seek(0);
          sortie << taille;
          socketClientBanque.write(tampon.buffer());
        }
    }
  else if(ui->radioButton_Retrait->isChecked())
    {
      commande = 'R';
      if(tampon.open(QIODevice::WriteOnly))
        {
          QDataStream sortie(&tampon);
          sortie << taille << commande << montant ;
          taille = tampon.size() - sizeof(taille);
          tampon.seek(0);
          sortie << taille;
          socketClientBanque.write(tampon.buffer());
        }
    }
}

void DabClientWidget::onQTcpSocketConnected()
{
  qDebug() << "Connected";
  // activer Operations Client
  ui->groupBox_Operations->setDisabled(false);
  // désactiver boutons port et adresse
  ui->lineEdit_Port->setDisabled(true);
  ui->lineEdit_IP->setDisabled(true);
  // changer le texte du bouton Connexion
  ui->pushButton_Connexion->setText("Déconnexion");
}

void DabClientWidget::onQTcpSocketDisconnected()
{
  qDebug() << "Disconnected";
  // désactiver Operations Client
  ui->groupBox_Operations->setDisabled(true);
  ui->lineEdit_Numero->clear();
  ui->lineEdit_Montant->clear();
  ui->lineEdit_Message->clear();
  // désactiver boutons port et adresse
  ui->lineEdit_Port->setDisabled(false);
  ui->lineEdit_IP->setDisabled(false);
  // changer le texte du bouton Connexion
  ui->pushButton_Connexion->setText("Connexion");
}

void DabClientWidget::onQTcpSocketReadyRead()
{
  quint16 taille = 0;
  QString message;
  if(socketClientBanque.bytesAvailable() >= static_cast<qint64>(sizeof(taille)))
    {
      QDataStream entree(&socketClientBanque);
      entree >> taille;
      if (socketClientBanque.bytesAvailable() >= static_cast<qint64>(taille))
        {
          entree >> message;
          ui->lineEdit_Message->setText(message);
        }
    }
}

void DabClientWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
  switch(socketState)
    {
    case QAbstractSocket::UnconnectedState: ui->textEdit_Etat->append("The socket is not connected.");break;
    case QAbstractSocket::HostLookupState: ui->textEdit_Etat->append("The socket is performing a host name lookup.");break;
    case QAbstractSocket::ConnectingState: ui->textEdit_Etat->append("The socket has started establishing a connection.");break;
    case QAbstractSocket::ConnectedState: ui->textEdit_Etat->append("A connection is established.");break;
    case QAbstractSocket::BoundState: ui->textEdit_Etat->append("The socket is bound to an address and port.");break;
    case QAbstractSocket::ClosingState: ui->textEdit_Etat->append("The socket is about to close (data may still be waiting to be written).");break;
    case QAbstractSocket::ListeningState: ui->textEdit_Etat->append("For internal use only.");break;
    }
}

void DabClientWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketClientBanque.errorString());
}

void DabClientWidget::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void DabClientWidget::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void DabClientWidget::onQTcpSocketBytesWritten(qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

