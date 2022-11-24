#include "serveurmonowidget.h"
#include "ui_serveurmonowidget.h"

ServeurMonoWidget::ServeurMonoWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ServeurMonoWidget)
{
  ui->setupUi(this);
  socketEcouteServeur = new QTcpServer();
  process = new QProcess(this);
  connect(socketEcouteServeur,&QTcpServer::acceptError,this,&ServeurMonoWidget::onQTcpServerAcceptError);
  connect(socketEcouteServeur,&QTcpServer::newConnection,this,&ServeurMonoWidget::onQTcpServerNewConnection);
  connect(process, &QProcess::readyReadStandardOutput,this,&ServeurMonoWidget::onQProcessReadyReadStandardOutput);
}

ServeurMonoWidget::~ServeurMonoWidget()
{
  delete ui;
  delete socketEcouteServeur;
  delete process;
}

void ServeurMonoWidget::on_pushButton_Lancer_clicked()
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

void ServeurMonoWidget::onQTcpServerAcceptError(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketEcouteServeur->errorString());
}

void ServeurMonoWidget::onQTcpServerNewConnection()
{
  ui->textEdit_Etat->append("New connection");
  // récupération de socket de communication avec le client
  socketDialogueClient = socketEcouteServeur->nextPendingConnection();
  connect(socketDialogueClient, &QTcpSocket::connected,this,&ServeurMonoWidget::onQTcpSocketConnected);
  connect(socketDialogueClient, &QTcpSocket::disconnected,this,&ServeurMonoWidget::onQTcpSocketDisconnected);
  connect(socketDialogueClient, &QTcpSocket::readyRead,this,&ServeurMonoWidget::onQTcpSocketReadyRead);
  connect(socketDialogueClient, &QTcpSocket::stateChanged,this,&ServeurMonoWidget::onQTcpSocketStateChanged);
  connect(socketDialogueClient, &QTcpSocket::errorOccurred,this,&ServeurMonoWidget::onQTcpSocketErrorOccurred);
  connect(socketDialogueClient, &QTcpSocket::hostFound,this,&ServeurMonoWidget::onQTcpSocketHostFound);
  connect(socketDialogueClient, &QTcpSocket::aboutToClose,this,&ServeurMonoWidget::onQTcpSocketAboutToClose);
  connect(socketDialogueClient, &QTcpSocket::bytesWritten,this,&ServeurMonoWidget::onQTcpSocketBytesWritten);
}

void ServeurMonoWidget::onQTcpSocketConnected()
{
  ui->textEdit_Messages->append("Client Connected");
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(true);
  ui->spinBox_Port->setDisabled(true);
}

void ServeurMonoWidget::onQTcpSocketDisconnected()
{
  disconnect(socketDialogueClient,nullptr,this,nullptr);
  socketDialogueClient->deleteLater();
  socketDialogueClient = nullptr;
  ui->textEdit_Messages->append("Client Disconnected");
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(false);
  ui->spinBox_Port->setDisabled(false);
}

void ServeurMonoWidget::onQTcpSocketReadyRead()
{
  QByteArray data;
  QString reponse;
  ui->textEdit_Etat->append("Socket ready to read");
  data = socketDialogueClient->readAll();
  ui->textEdit_Messages->append("Received message : " + data);
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

void ServeurMonoWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
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

void ServeurMonoWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketDialogueClient->errorString());
}

void ServeurMonoWidget::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void ServeurMonoWidget::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void ServeurMonoWidget::onQTcpSocketBytesWritten(qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

void ServeurMonoWidget::onQProcessReadyReadStandardOutput()
{
  QString reponse = process->readAllStandardOutput();
  if(!reponse.isEmpty())
    socketDialogueClient->write(reponse.toLatin1());
}
