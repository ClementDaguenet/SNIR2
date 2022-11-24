#include "serveurmultiwidget.h"
#include "ui_serveurmultiwidget.h"

ServeurMultiWidget::ServeurMultiWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ServeurMultiWidget)
{
  ui->setupUi(this);
  socketEcouteServeur = new QTcpServer(this);
  connect(socketEcouteServeur,&QTcpServer::acceptError,this,&ServeurMultiWidget::onQTcpServerAcceptError);
  connect(socketEcouteServeur,&QTcpServer::newConnection,this,&ServeurMultiWidget::onQTcpServerNewConnection);
}

ServeurMultiWidget::~ServeurMultiWidget()
{
  delete ui;
}

void ServeurMultiWidget::on_pushButton_Lancer_clicked()
{
  if(socketEcouteServeur->listen(QHostAddress::Any,ui->spinBox_Port->value()))
    {
      ui->textEdit_Etat->append("Successful launch");
      ui->spinBox_Port->setDisabled(true);
      ui->pushButton_Lancer->setDisabled(true);
    }
  else
    {
      ui->textEdit_Etat->append("Failed launch : " + socketEcouteServeur->errorString());
    }
}

void ServeurMultiWidget::onQTcpServerAcceptError(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketEcouteServeur->errorString());
}

void ServeurMultiWidget::onQTcpServerNewConnection()
{
  ui->textEdit_Etat->append("New connection");
  QTcpSocket *socketDialogueClient;
  QProcess *process = new QProcess(this);
  // récupération de socket de communication avec le client
  socketDialogueClient = socketEcouteServeur->nextPendingConnection();
  connect(socketDialogueClient, &QTcpSocket::connected,this,&ServeurMultiWidget::onQTcpSocketConnected);
  connect(socketDialogueClient, &QTcpSocket::disconnected,this,&ServeurMultiWidget::onQTcpSocketDisconnected);
  connect(socketDialogueClient, &QTcpSocket::readyRead,this,&ServeurMultiWidget::onQTcpSocketReadyRead);
  connect(socketDialogueClient, &QTcpSocket::stateChanged,this,&ServeurMultiWidget::onQTcpSocketStateChanged);
  connect(socketDialogueClient, &QTcpSocket::errorOccurred,this,&ServeurMultiWidget::onQTcpSocketErrorOccurred);
  connect(socketDialogueClient, &QTcpSocket::hostFound,this,&ServeurMultiWidget::onQTcpSocketHostFound);
  connect(socketDialogueClient, &QTcpSocket::aboutToClose,this,&ServeurMultiWidget::onQTcpSocketAboutToClose);
  connect(socketDialogueClient, &QTcpSocket::bytesWritten,this,&ServeurMultiWidget::onQTcpSocketBytesWritten);
  connect(process, &QProcess::readyReadStandardOutput,this,&ServeurMultiWidget::onQProcessReadyReadStandardOutput);
  // ajout du client dans la liste des process

  QHostAddress adresseClient = socketDialogueClient->peerAddress();
  if (adresseClient.toIPv4Address())
    {
      QString adresse = adresseClient.toString();
      QStringList ipv4 = adresse.split("f:");
      ui->textEdit_Messages->append("Client " + ipv4.at(1) + "  Connected");
    }
  listeSocketsDialogueClient.append(socketDialogueClient);
  listeProcess.append(process);
}

void ServeurMultiWidget::onQTcpSocketConnected()
{
  ui->textEdit_Messages->append("Client Connected");
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(true);
  ui->spinBox_Port->setDisabled(true);
}

void ServeurMultiWidget::onQTcpSocketDisconnected()
{
  // récupération du dernier client
  QTcpSocket *socketDialogueClient;
  socketDialogueClient = qobject_cast<QTcpSocket*>(sender());
  disconnect(socketDialogueClient,nullptr,this,nullptr);

  QHostAddress adresseClient = socketDialogueClient->peerAddress();
  if (adresseClient.toIPv4Address())
    {
      QString adresse = adresseClient.toString();
      QStringList ipv4 = adresse.split("f:");
      ui->textEdit_Messages->append("Client " + ipv4.at(1) + "  Disconnected");
    }

  // récupération de l'indice dans la liste du dernier client pour l'enlever
  int indexClient = listeSocketsDialogueClient.indexOf(socketDialogueClient);
  listeProcess.removeAt(indexClient);
  listeSocketsDialogueClient.removeOne(socketDialogueClient);
  socketDialogueClient->deleteLater();
  socketDialogueClient = nullptr;
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(false);
  ui->spinBox_Port->setDisabled(false);
}

void ServeurMultiWidget::onQTcpSocketReadyRead()
{
  // récupération du dernier client
  QTcpSocket *socketDialogueClient;
  socketDialogueClient = qobject_cast<QTcpSocket*>(sender());
  // récupération de l'indice dans la liste du dernier client pour le chercher
  QProcess *process;
  int indexClient = listeSocketsDialogueClient.indexOf(socketDialogueClient);
  process = listeProcess.at(indexClient);
  QByteArray data;
  QString reponse;
  ui->textEdit_Etat->append("Socket ready to read");
  data = socketDialogueClient->readAll();
  ui->textEdit_Messages->append("Received message : " + data);
  // réponse à envoyer selon la lettre reçue
  if(data == "u") // username
    {
      reponse = getenv("USER");
      socketDialogueClient->write(reponse.toLatin1());
    }
  else if (data == "c") // machine
    {
      reponse = QHostInfo::localHostName();
      socketDialogueClient->write(reponse.toLatin1());
    }
  else if (data == "o") // os
    {
      process->start("uname");
    }
  else if (data == "a") // archi
    {
      process->start("uname",QStringList("-p"));
    }
}

void ServeurMultiWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
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

void ServeurMultiWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  QTcpSocket *socketDialogueClient;
  socketDialogueClient = qobject_cast<QTcpSocket*>(sender());
  ui->textEdit_Etat->append(socketDialogueClient->errorString());
}

void ServeurMultiWidget::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void ServeurMultiWidget::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void ServeurMultiWidget::onQTcpSocketBytesWritten(qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

void ServeurMultiWidget::onQProcessReadyReadStandardOutput()
{
  // récupération du dernier process
  QTcpSocket *socketDialogueClient;
  QProcess *process = qobject_cast<QProcess*>(sender());
  int indexClient = listeProcess.indexOf(process);
  socketDialogueClient = listeSocketsDialogueClient.at(indexClient);
  QString reponse = process->readAllStandardOutput();
  if(!reponse.isEmpty())
    socketDialogueClient->write(reponse.toLatin1());
}

