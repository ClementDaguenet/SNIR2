#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Log),
  socketEcoute(new QTcpServer(this))
{
  ui->setupUi(this);
  setWindowTitle("Log Server");
  ui->label_State->hide();
  ui->label_Player->hide();
  ui->lcdNumber_Player->hide();
  ui->lineEdit_Party->hide();
  ui->label_State->setMaximumSize(171,38);
  ui->label_Player->setMaximumSize(80,24);
  ui->lcdNumber_Player->setMaximumSize(80,24);

  nbPlayers = 0;
}

Log::~Log()
{
  delete CATScene;
  delete ui;
}

void Log::on_pushButton_Start_clicked()
{
  if(ui->pushButton_Start->text() == "Start")
    {
      if(!socketEcoute->listen(QHostAddress::Any,ui->spinBox_Port->value()))
        {
          QString message = "Error in server starting : " + socketEcoute->errorString();
          qDebug() << message;
          socketEcoute->close();
        }
      else
        {
          connect(socketEcoute,&QTcpServer::newConnection,this,&Log::onQTcpServer_newConnection);
          LogState("Start");
          CATScene = new CATServeur();
          CATScene->show();
          move(478,200);
          CATScene->PlaceTreasure(GiveUniquePosition());
        }
    }
  else if(ui->pushButton_Start->text() == "Stop")
    {
      LogState("Stop");
      CATScene->hide();
      move(800,300);
    }
}

void Log::onQTcpServer_newConnection()
{
  QTcpSocket *client = socketEcoute->nextPendingConnection();
  connect(client, &QTcpSocket::readyRead,this, &Log::onQTcpSocket_readyRead);
  connect(client, &QTcpSocket::disconnected,this, &Log::onQTcpSocket_disconnected);
  QHostAddress addresseClient = client->peerAddress();
  if (addresseClient.toIPv4Address())
    {
      QString adresse = addresseClient.toString();
      QStringList ipv4 = adresse.split("f:");
      qDebug() << this << ipv4.at(1) + " Connected";
    }
  listeSocketsClient.append(client);
  QPoint pointDepart(GiveUniquePosition());
  listePositions.append(pointDepart);
  CATScene->CreatePlayer(pointDepart);
  nbPlayers += 1;
  ui->lcdNumber_Player->display(nbPlayers);
  SendData(client,pointDepart,"vide");
}

void Log::onQTcpSocket_readyRead()
{
  QChar commande;
  quint16 taille=0;
  QTcpSocket *socketVersClient=qobject_cast<QTcpSocket*>(sender());
  int indexClient = listeSocketsClient.indexOf(socketVersClient);
  QPoint pos = listePositions.at(indexClient);
  if (socketVersClient->bytesAvailable() >= (qint64)sizeof(taille))
    {
      QDataStream in(socketVersClient);
      in >> taille;
      if (socketVersClient->bytesAvailable() >= (qint64)taille)
        {
          // decomposition de la trame
          in >> commande;
          switch (commande.toLatin1()) {
            case 'D':
              pos.setY((pos.y()+3) % TAILLE_Y);
              CATScene->ChangePlayerPosition(indexClient,pos);
              CATScene->ChangePlayerDirection(indexClient,"down");
              break;
            case 'U':
              pos.setY(abs(pos.y()-3));
              CATScene->ChangePlayerPosition(indexClient,pos);
              CATScene->ChangePlayerDirection(indexClient,"up");
              break;
            case 'R':
              pos.setX((pos.x()+3) % TAILLE_X);
              CATScene->ChangePlayerPosition(indexClient,pos);
              CATScene->ChangePlayerDirection(indexClient,"right");
              break; // 178 266
            case 'L':
              pos.setX(abs(pos.x()-3));
              CATScene->ChangePlayerPosition(indexClient,pos);
              CATScene->ChangePlayerDirection(indexClient,"left");
              break;
            }
          // collision ?
          if (listePositions.contains(pos))
            {
              int indexAutre = listePositions.indexOf(pos);
              listePositions.replace(indexClient,GiveUniquePosition());
              listePositions.replace(indexAutre,GiveUniquePosition());
              // envoyer position aux clients
              SendData(socketVersClient,listePositions.at(indexClient),"collision");
              SendData(listeSocketsClient.at(indexAutre),listePositions.at(indexAutre),"collision");
            }
          else
            {
              // gagnant?
              if (pos == CATScene->GetTreasurePosition())
                {
                  qDebug() << this << "A winner";
                  // envoyer message à tous les clients
                  foreach(QTcpSocket *client, listeSocketsClient)
                    {
                      QHostAddress addresseClient = socketVersClient->peerAddress();
                      if (addresseClient.toIPv4Address())
                        {
                          QString adresse = addresseClient.toString();
                          QStringList ipv4 = adresse.split("f:");
                          SendData(client,QPoint(-1,-1),"Victory of "+ipv4.at(1));
                          CATScene->OpenTreasure("open");
                          Wait(2500);
                          CATScene->OpenTreasure("close");
                        }
                    }
                  //deconnecter tous les client
                  foreach(QTcpSocket *client, listeSocketsClient)
                    {
                      client->disconnectFromHost();
                      qDebug() << "Log out";
                    }
                  CATScene->PlaceTreasure(GiveUniquePosition());
                }
              else
                {
                  // autre
                  listePositions.replace(indexClient,pos);
                  // envoyer position au client
                  SendData(socketVersClient,pos,"vide");
                }
            }
          CATScene->ChangePlayerPosition(indexClient,pos);
        }
    }
}

void Log::onQTcpSocket_disconnected()
{
  qDebug() << this << "Client disconnected";
  nbPlayers -= 1;
  ui->lcdNumber_Player->display(nbPlayers);
  QTcpSocket *socketVersClient=qobject_cast<QTcpSocket*>(sender());
  int indexClient = listeSocketsClient.indexOf(socketVersClient);
  listeSocketsClient.removeAt(indexClient);
  listePositions.removeAt(indexClient);
  disconnect(socketVersClient,&QTcpSocket::readyRead,this,&Log::onQTcpSocket_readyRead);
  disconnect(socketVersClient,&QTcpSocket::disconnected,this,&Log::onQTcpSocket_disconnected);

  qDebug() <<listePositions.size();

}

void Log::LogState(const QString _state)
{
  if(_state == "Start")
    {
      ui->pushButton_Start->setText("Stop");
      ui->label_State->setText("Server launched");
      ui->label_State->show();
      ui->label_Player->show();
      ui->lcdNumber_Player->show();
      ui->lineEdit_Party->show();
      ui->label_Port->hide();
      ui->spinBox_Port->hide();
    }
  else if(_state == "Stop")
    {
      ui->pushButton_Start->setText("Start");
      ui->label_State->hide();
      ui->label_Player->hide();
      ui->lcdNumber_Player->hide();
      ui->lineEdit_Party->hide();
      ui->label_Port->show();
      ui->spinBox_Port->show();
    }
}

void Log::SendData(QTcpSocket *client, QPoint pt, QString msg)
{
  quint16 taille = 0;
  QBuffer tampon;
  tampon.open(QIODevice::WriteOnly);
  // association du tampon au flux de sortie
  QDataStream out(&tampon);
  // construction de la trame
  out << taille << pt << msg << CalculcateDistance(pt);
  // calcul de la taille de la trame
  taille = tampon.size()-sizeof(taille);
  // placement sur la premiere position du flux pour pouvoir modifier la taille
  tampon.seek(0);
  //modification de la trame avec la taille reel de la trame
  out << taille;
  // envoi du QByteArray du tampon via la socket
  client->write(tampon.buffer());
  qDebug() << "Pos send : " << pt;
}

QPoint Log::GiveUniquePosition()
{
  QRandomGenerator rand;
  QPoint pt;
  rand.seed(QDateTime::currentMSecsSinceEpoch());
  int ligne, colonne;
  do
    {
      ligne = rand.bounded(TAILLE_X - 100);
      qDebug() << "Ligne : " << ligne;

      colonne = rand.bounded(TAILLE_Y - 100);
      qDebug() << "Colonne : " << colonne;

      pt = QPoint(ligne+50,colonne+50);
    }
  while (listePositions.contains(pt));

  return pt;
}

double Log::CalculcateDistance(QPoint _position)
{
  QPoint d = QPoint(10,10) - _position;
  return sqrt(d.x()*d.x() + d.y()* d.y());
}

void Log::Wait(int _milliseconds)
{
  QTimer timer;
  timer.start(_milliseconds);
  QEventLoop loop(this);
  QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  loop.exec();
}

void Log::closeEvent(QCloseEvent *event)
{
  qDebug() << "Grid closed";
  CATScene->close();
}
