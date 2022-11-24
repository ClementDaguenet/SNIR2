#include "uiclienttcp.h"
#include "ui_uiclienttcp.h"

UIClientTcp::UIClientTcp(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::UIClientTcp)
{
  ui->setupUi(this);
  // désactiver bouton envoyer
  ui->pushButton_Envoyer->setDisabled(true);
  // désactiver texte à envoyer
  ui->lineEdit_Texte->setDisabled(true);
  // association signal/slot pour sockVersServeur
  connect(&sockVersServeur, &QTcpSocket::connected,this,&UIClientTcp::onQTcpSocketConnected);
  connect(&sockVersServeur, &QTcpSocket::disconnected,this,&UIClientTcp::onQTcpSocketDisconnected);
  connect(&sockVersServeur, &QTcpSocket::readyRead,this,&UIClientTcp::onQTcpSocketReadyRead);
  connect(&sockVersServeur, &QTcpSocket::stateChanged,this,&UIClientTcp::onQTcpSocketStateChanged);
  connect(&sockVersServeur, &QTcpSocket::errorOccurred,this,&UIClientTcp::onQTcpSocketErrorOccurred);
  connect(&sockVersServeur, &QTcpSocket::hostFound,this,&UIClientTcp::onQTcpSocketHostFound);
  connect(&sockVersServeur, &QTcpSocket::aboutToClose,this,&UIClientTcp::onQTcpSocketAboutToClose);
  connect(&sockVersServeur, &QTcpSocket::bytesWritten,this,&UIClientTcp::onQTcpSocketBytesWritten);
  connect(&sockVersServeur, &QTcpSocket::channelBytesWritten,this,&UIClientTcp::onQTcpSocketChannelsBytesWritten);
  connect(&sockVersServeur, &QTcpSocket::channelReadyRead,this,&UIClientTcp::onQTcpSocketChannelReadyRead);
  connect(&sockVersServeur, &QTcpSocket::readChannelFinished,this,&UIClientTcp::onQTcpSocketReadChannelFinished);
}

UIClientTcp::~UIClientTcp()
{
  delete ui;
}


void UIClientTcp::on_pushButton_Connexion_clicked()
{
  sockVersServeur.connectToHost(ui->lineEdit_IP->text(),ui->spinBox_Port->value());
}

void UIClientTcp::on_pushButton_Envoyer_clicked()
{
  sockVersServeur.write(ui->lineEdit_Texte->text().toUtf8());
}

void UIClientTcp::onQTcpSocketConnected()
{
  qDebug() << "Connected";
  // activer bouton envoyer
  ui->pushButton_Envoyer->setDisabled(false);
  // activer texte à envoyer
  ui->lineEdit_Texte->setDisabled(false);
  // désactiver boutons connexion port et adresse
  ui->pushButton_Connexion->setDisabled(true);
  ui->spinBox_Port->setDisabled(true);
  ui->lineEdit_IP->setDisabled(true);
}

void UIClientTcp::onQTcpSocketDisconnected()
{
  qDebug() << "Disconnected";
  // activer bouton envoyer
  ui->pushButton_Envoyer->setDisabled(true);
  // activer texte à envoyer
  ui->lineEdit_Texte->setDisabled(true);
  // désactiver boutons connexion port et adresse
  ui->pushButton_Connexion->setDisabled(false);
  ui->spinBox_Port->setDisabled(false);
  ui->lineEdit_IP->setDisabled(false);
}

void UIClientTcp::onQTcpSocketReadyRead()
{
  QByteArray reponse;
  reponse = sockVersServeur.readAll();
  ui->textEdit_Messages->append(reponse);
}

void UIClientTcp::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
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

void UIClientTcp::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  ui->textEdit_Etat->append(sockVersServeur.errorString());
}

void UIClientTcp::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void UIClientTcp::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void UIClientTcp::onQTcpSocketBytesWritten(qint64 bytes)
{
    ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

void UIClientTcp::onQTcpSocketChannelsBytesWritten(int channel, qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written on the channel " + QString::number(channel) + ".");
}

void UIClientTcp::onQTcpSocketChannelReadyRead(int channel)
{
  ui->textEdit_Etat->append("Read on the channel " + QString::number(channel) + ".");
}

void UIClientTcp::onQTcpSocketReadChannelFinished()
{
  ui->textEdit_Etat->append("Read on the channel finished.");
}
