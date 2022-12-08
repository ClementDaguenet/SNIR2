#include "serveurweb.h"
#include "ui_serveurweb.h"

ServeurWeb::ServeurWeb(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::ServeurWeb)
{
  ui->setupUi(this);

  socketServeur = new QWebSocketServer("Web Server", QWebSocketServer::NonSecureMode);
  connect(socketServeur, &QWebSocketServer::newConnection, this, &ServeurWeb::onQWebSocketServer_newConnection);
}

ServeurWeb::~ServeurWeb()
{
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
      ui->textEdit_Console->append("Launch Error : " + socketServeur->errorString());
    }
  else
    {
      ui->textEdit_Console->append("Successful launch !");
    }
}

void ServeurWeb::onQWebSocketServer_newConnection()
{
  QWebSocket *client = socketServeur->nextPendingConnection();
  connect(client, &QWebSocket::textMessageReceived, this, &ServeurWeb::onQWebSocket_textMessageReceived);
  listeClients.append(client);
  QTimer *timerDate = new QTimer;
  connect(timerDate,&QTimer::timeout,this,&ServeurWeb::onTimerDate_timeout);
  listeTimerDate.append(timerDate);
  ui->textEdit_Console->append("New Connection");
}

void ServeurWeb::onQWebSocket_textMessageReceived(QString _message)
{
  QWebSocket *client = qobject_cast<QWebSocket *>(sender());
  int indexTimer = listeClients.indexOf(client);
  if(_message == "date")
   listeTimerDate.at(indexTimer)->start(TEMPO_DATE);
}

void ServeurWeb::onTimerDate_timeout()
{
  QTimer *timer = qobject_cast<QTimer *>(sender());
  int indexClient = listeTimerDate.indexOf(timer);
  QString date = QDateTime::currentDateTime().toString();
  listeClients.at(indexClient)->sendTextMessage(date);
  ui->textEdit_Donnees->setText("Sended : " + date);
}
