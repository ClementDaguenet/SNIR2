#include "uiservertcp.h"
#include "ui_uiservertcp.h"

UIServerTcp::UIServerTcp(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::UIServerTcp)
{
  ui->setupUi(this);
  connect(&socketServer,&QTcpServer::acceptError,this,&UIServerTcp::onQTcpServerAcceptError);
  connect(&socketServer,&QTcpServer::newConnection,this,&UIServerTcp::onQTcpServerNewConnection);
}

UIServerTcp::~UIServerTcp()
{
  delete ui;
}


void UIServerTcp::on_pushButton_Lancer_clicked()
{
  if(socketServer.listen(QHostAddress::Any,ui->spinBox_Port->value()))
    {
      ui->textEdit_Etat->append("Launch successed");
    }
  else
    {
      ui->textEdit_Etat->append("Launch failed");
    }
}

void UIServerTcp::onQTcpServerAcceptError(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketServer.errorString());
}

void UIServerTcp::onQTcpServerNewConnection()
{
  ui->textEdit_Etat->append("New connection");
  // récupération de socket de communication avec le client
  socketClient = socketServer.nextPendingConnection();
  connect(socketClient, &QTcpSocket::connected,this,&UIServerTcp::onQTcpSocketConnected);
  connect(socketClient, &QTcpSocket::disconnected,this,&UIServerTcp::onQTcpSocketDisconnected);
  connect(socketClient, &QTcpSocket::readyRead,this,&UIServerTcp::onQTcpSocketReadyRead);
  connect(socketClient, &QTcpSocket::stateChanged,this,&UIServerTcp::onQTcpSocketStateChanged);
  connect(socketClient, &QTcpSocket::errorOccurred,this,&UIServerTcp::onQTcpSocketErrorOccurred);
  connect(socketClient, &QTcpSocket::hostFound,this,&UIServerTcp::onQTcpSocketHostFound);
  connect(socketClient, &QTcpSocket::aboutToClose,this,&UIServerTcp::onQTcpSocketAboutToClose);
  connect(socketClient, &QTcpSocket::bytesWritten,this,&UIServerTcp::onQTcpSocketBytesWritten);
  connect(socketClient, &QTcpSocket::channelBytesWritten,this,&UIServerTcp::onQTcpSocketChannelsBytesWritten);
  connect(socketClient, &QTcpSocket::channelReadyRead,this,&UIServerTcp::onQTcpSocketChannelReadyRead);
  connect(socketClient, &QTcpSocket::readChannelFinished,this,&UIServerTcp::onQTcpSocketReadChannelFinished);
}

void UIServerTcp::onQTcpSocketConnected()
{
  ui->textEdit_Messages->append("Client Connected");
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(true);
  ui->spinBox_Port->setDisabled(true);
}

void UIServerTcp::onQTcpSocketDisconnected()
{
  ui->textEdit_Messages->append("Client Disconnected");
  // désactiver boutons connexion port
  ui->pushButton_Lancer->setDisabled(false);
  ui->spinBox_Port->setDisabled(false);
}

void UIServerTcp::onQTcpSocketReadyRead()
{
  QByteArray data;
  ui->textEdit_Etat->append("Socket ready to read");
  data = socketClient->readAll();
  ui->textEdit_Messages->append("Received message : " + data);
  socketClient->write("Received message : " + data);
}

void UIServerTcp::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
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

void UIServerTcp::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketClient->errorString());
}

void UIServerTcp::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void UIServerTcp::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void UIServerTcp::onQTcpSocketBytesWritten(qint64 bytes)
{
    ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

void UIServerTcp::onQTcpSocketChannelsBytesWritten(int channel, qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written on the channel " + QString::number(channel) + ".");
}

void UIServerTcp::onQTcpSocketChannelReadyRead(int channel)
{
  ui->textEdit_Etat->append("Read on the channel " + QString::number(channel) + ".");
}

void UIServerTcp::onQTcpSocketReadChannelFinished()
{
  ui->textEdit_Etat->append("Read on the channel finished.");
}
