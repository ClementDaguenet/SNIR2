#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::AuditClientWidget)
{
  ui->setupUi(this);

  socketDeDialogueAvecServeur = new QTcpSocket(this);
  // association signal/slot pour socketDeDialogueAvecServeur
  connect(socketDeDialogueAvecServeur, &QTcpSocket::connected,this,&AuditClientWidget::onQTcpSocketConnected);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::disconnected,this,&AuditClientWidget::onQTcpSocketDisconnected);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::readyRead,this,&AuditClientWidget::onQTcpSocketReadyRead);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::stateChanged,this,&AuditClientWidget::onQTcpSocketStateChanged);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::errorOccurred,this,&AuditClientWidget::onQTcpSocketErrorOccurred);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::hostFound,this,&AuditClientWidget::onQTcpSocketHostFound);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::aboutToClose,this,&AuditClientWidget::onQTcpSocketAboutToClose);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::bytesWritten,this,&AuditClientWidget::onQTcpSocketBytesWritten);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::channelBytesWritten,this,&AuditClientWidget::onQTcpSocketChannelsBytesWritten);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::channelReadyRead,this,&AuditClientWidget::onQTcpSocketChannelReadyRead);
  connect(socketDeDialogueAvecServeur, &QTcpSocket::readChannelFinished,this,&AuditClientWidget::onQTcpSocketReadChannelFinished);
}

AuditClientWidget::~AuditClientWidget()
{
  delete ui;
}

void AuditClientWidget::on_pushButton_Connexion_clicked()
{
  if(ui->pushButton_Connexion->text()=="Déconnexion")
    {
      socketDeDialogueAvecServeur->disconnectFromHost();
    }
  else if(ui->pushButton_Connexion->text()=="Connexion")
    {
      socketDeDialogueAvecServeur->connectToHost(ui->lineEdit_IP->text(),ui->spinBox_Port->value());
    }
}

void AuditClientWidget::on_pushButton_Name_clicked()
{
  typeDeDemande="c";
  socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::on_pushButton_User_clicked()
{
  typeDeDemande="u";
  socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::on_pushButton_Archi_clicked()
{
  typeDeDemande="a";
  socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::on_pushButton_OS_clicked()
{
  typeDeDemande="o";
  socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::onQTcpSocketConnected()
{
  qDebug() << "Connected";
  // activer Informations Client
  ui->groupBox_Client->setDisabled(false);
  // désactiver boutons port et adresse
  ui->spinBox_Port->setDisabled(true);
  ui->lineEdit_IP->setDisabled(true);
  // changer le texte du bouton Connexion
  ui->pushButton_Connexion->setText("Déconnexion");
}

void AuditClientWidget::onQTcpSocketDisconnected()
{
  qDebug() << "Disconnected";
  // désactiver Informations Client
  ui->groupBox_Client->setDisabled(true);
  ui->lineEdit_Name->clear();
  ui->lineEdit_User->clear();
  ui->lineEdit_Archi->clear();
  ui->lineEdit_OS->clear();
  // désactiver boutons port et adresse
  ui->spinBox_Port->setDisabled(false);
  ui->lineEdit_IP->setDisabled(false);
  // changer le texte du bouton Connexion
  ui->pushButton_Connexion->setText("Connexion");
}

void AuditClientWidget::onQTcpSocketReadyRead()
{
  QByteArray reponse;
  reponse = socketDeDialogueAvecServeur->readAll();
  ui->textEdit_Etat->append(reponse);
  switch(typeDeDemande.at(0).toLatin1())
    {
    case 'c': ui->lineEdit_Name->setText(reponse);break;
    case 'u': ui->lineEdit_User->setText(reponse);break;
    case 'a': ui->lineEdit_Archi->setText(reponse);break;
    case 'o': ui->lineEdit_OS->setText(reponse);break;
    }
}

void AuditClientWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
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

void AuditClientWidget::onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError)
{
  Q_UNUSED(socketError);
  ui->textEdit_Etat->append(socketDeDialogueAvecServeur->errorString());
}

void AuditClientWidget::onQTcpSocketHostFound()
{
  ui->textEdit_Etat->append("Host found.");
}

void AuditClientWidget::onQTcpSocketAboutToClose()
{
  ui->textEdit_Etat->append("The socket is about to close.");
}

void AuditClientWidget::onQTcpSocketBytesWritten(qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written.");
}

void AuditClientWidget::onQTcpSocketChannelsBytesWritten(int channel, qint64 bytes)
{
  ui->textEdit_Etat->append(QString::number(bytes) + " bytes written on the channel " + QString::number(channel) + ".");
}

void AuditClientWidget::onQTcpSocketChannelReadyRead(int channel)
{
  ui->textEdit_Etat->append("Read on the channel " + QString::number(channel) + ".");
}

void AuditClientWidget::onQTcpSocketReadChannelFinished()
{
  ui->textEdit_Etat->append("Read on the channel finished.");
}
