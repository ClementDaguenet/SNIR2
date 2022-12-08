#include "serveurweb.h"
#include "ui_serveurweb.h"

ServeurWeb::ServeurWeb(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ServeurWeb)
{
  ui->setupUi(this);

  socketServeur = new QWebSocketServer("Web Server", QWebSocketServer::NonSecureMode);
  connect(socketServeur, &QWebSocketServer::newConnection, this, &ServeurWeb::onQWebSocketServer_newConnection);

  timerDate = new QTimer;
  connect(timerDate,&QTimer::timeout,this,&ServeurWeb::onTimerDate_timeout);
}

ServeurWeb::~ServeurWeb()
{
  delete timerDate;
  delete socketClient;
  delete socketServeur;
  delete ui;
}

void ServeurWeb::on_pushButton_Lancer_clicked()
{
  ui->pushButton_Lancer->setDisabled(true);
  ui->pushButton_Lancer->setStyleSheet("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;");
  ui->spinBox_Port->setDisabled(true);
  ui->spinBox_Port->setStyleSheet("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;");
  if(!socketServeur->listen(QHostAddress::Any, ui->spinBox_Port->value()))
    {
      ui->textEdit_Console->setText("Launch Error : " + socketServeur->errorString());
    }
  else
    {
      ui->textEdit_Console->setText("Successful launch !");
    }
}

void ServeurWeb::onQWebSocketServer_newConnection()
{
  socketClient = socketServeur->nextPendingConnection();
  connect(socketClient, &QWebSocket::textMessageReceived, this, &ServeurWeb::onQWebSocket_textMessageReceived);
}

void ServeurWeb::onQWebSocket_textMessageReceived(QString _message)
{
  if(_message == "date")
    timerDate->start(TEMPO_DATE);
}

void ServeurWeb::onTimerDate_timeout()
{
  QString date = QDateTime::currentDateTime().toString();
  socketClient->sendTextMessage(date);
  ui->textEdit_Donnees->setText("Sended : " + date);
}
