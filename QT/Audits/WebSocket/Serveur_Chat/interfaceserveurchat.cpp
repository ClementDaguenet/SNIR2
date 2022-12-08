#include "interfaceserveurchat.h"
#include "ui_interfaceserveurchat.h"

InterfaceServeurChat::InterfaceServeurChat(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::InterfaceServeurChat)
{
  ui->setupUi(this);

  socketServeur = new QWebSocketServer("Web Server", QWebSocketServer::NonSecureMode);
  connect(socketServeur, &QWebSocketServer::newConnection, this, &InterfaceServeurChat::onQWebSocketServer_newConnection);
}

InterfaceServeurChat::~InterfaceServeurChat()
{
  delete socketServeur;
  delete ui;
}

void InterfaceServeurChat::BroadcastMessage(QString _message)
{
  ui->textEdit_Receive->append("Moi : " + _message);
  ui->lineEdit_Send->clear();
  foreach (QWebSocket *c, listeClients) {
      c->sendTextMessage(_message);
  }
}

void InterfaceServeurChat::on_pushButton_Lancer_clicked()
{
  if(!socketServeur->listen(QHostAddress::Any, ui->spinBox_Port->value()))
    {
      ui->textEdit_Console->append("Launch Error : " + socketServeur->errorString());
    }
  else
    {
      ui->textEdit_Console->append("Successful launch !");
      ui->pushButton_Lancer->setDisabled(true);
      ui->pushButton_Lancer->setStyleSheet("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;");
      ui->spinBox_Port->setDisabled(true);
      ui->spinBox_Port->setStyleSheet("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;");
      ui->lineEdit_IP->setText(socketServeur->serverName());
    }
}

void InterfaceServeurChat::onQWebSocketServer_newConnection()
{
  ui->textEdit_Console->append("New Connection");
  QWebSocket *client = socketServeur->nextPendingConnection();
  connect(client, &QWebSocket::textMessageReceived, this, &InterfaceServeurChat::onQWebSocket_textMessageReceived);
  listeClients.append(client);
  QHostAddress adresseClient = client->peerAddress();
  if (adresseClient.toIPv4Address())
    {
      QString adresse = adresseClient.toString();
      QStringList ipv4 = adresse.split("f:");
      ui->textEdit_Console->append("Client " + ipv4.at(1) + "  Connected");
    }
}

void InterfaceServeurChat::onQWebSocket_textMessageReceived(const QString &_message)
{
  QWebSocket *client = qobject_cast<QWebSocket *>(sender());
  QHostAddress adresseClient = client->peerAddress();
  ui->textEdit_Receive->append( _message);
}

void InterfaceServeurChat::onQWebSocket_disconnected()
{
  QWebSocket *client = qobject_cast<QWebSocket*>(sender());
  disconnect(client,nullptr,this,nullptr);
  QHostAddress adresseClient = client->peerAddress();
  if (adresseClient.toIPv4Address())
    {
      QString adresse = adresseClient.toString();
      QStringList ipv4 = adresse.split("f:");
      ui->textEdit_Console->append("Client " + ipv4.at(1) + "  Disconnected");
    }
  listeClients.removeOne(client);
  client->deleteLater();
  client = nullptr;
  ui->pushButton_Lancer->setDisabled(false);
  ui->spinBox_Port->setDisabled(false);
}


void InterfaceServeurChat::on_pushButton_Envoyer_clicked()
{
  BroadcastMessage(ui->lineEdit_Send->text());
}

