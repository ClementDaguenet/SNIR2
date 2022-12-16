#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Log),
  socketDeDialogueAvecServeur(new QTcpSocket(this))
{
  ui->setupUi(this);
  setWindowTitle("Log Client");
  ui->label_State->hide();
  ui->label_Distance->hide();
  ui->lcdNumber_Distance->hide();
  ui->lineEdit_Party->hide();
  ui->label_State->setMaximumSize(171,38);
  ui->label_Distance->setMaximumSize(80,24);
  ui->lcdNumber_Distance->setMaximumSize(80,24);
  ui->lineEdit_Player->hide();
  ui->label_Player->hide();

  imgFolder = "../img/";
  musicFolder = "../sounds/";
  desactivate = "background: #00008B; border: 2px inset #ff0; font: bold 14px; color: #808080;";
  activate = "background: #00008B; border: 2px inset #ff0; font: bold 14px; color: white;";

  connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&Log::onQTcpSocket_connected);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&Log::onQTcpSocket_disconnected);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&Log::onQTcpSocket_hostFound);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&Log::onQTcpSocket_stateChanged);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&Log::onQTcpSocket_aboutToClose);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&Log::onQTcpSocket_bytesWritten);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::readChannelFinished,this,&Log::onQTcpSocket_readChannelFinished);
  connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&Log::onQTcpSocket_readyRead);
}

Log::~Log()
{
  delete ui;
}

void Log::CreateScene()
{
  setFocus();
  setWindowTitle("Chasse Au Trésor Client");
  QColor white(200,200,200);
  setFixedSize(1280,1024);
  scene = new QGraphicsScene();
  view = new QGraphicsView(this);
  scene->setSceneRect(0, 0, 1280, 724);

  // Borders
  QGraphicsRectItem *ligneLeft = new QGraphicsRectItem(5, 5, 5, 700);
  ligneLeft->setPen(white);
  ligneLeft->setBrush(white);
  QGraphicsRectItem *ligneRight = new QGraphicsRectItem(1265, 5, 5, 700);
  ligneRight->setPen(white);
  ligneRight->setBrush(white);
  QGraphicsRectItem *ligneUp = new QGraphicsRectItem(5, 5, 1260, 5);
  ligneUp->setPen(white);
  ligneUp->setBrush(white);
  QGraphicsRectItem *ligneDown = new QGraphicsRectItem(5, 705, 1260, 5);
  ligneDown->setPen(white);
  ligneDown->setBrush(white);

  // Map
  theMap = new QGraphicsPixmapItem(imgFolder + "map/map.png");
  theMap->setPos(0,0);
  theMap->mapRectFromScene(0,0,1280,724);
  scene->addItem(theMap);

  // House
  theHouse = new QGraphicsPixmapItem(imgFolder + "map/house.png");
  theHouse->setPos(1000,75);
  scene->addItem(theHouse);

  // Bushes
  theBush = new QGraphicsPixmapItem(imgFolder + "map/bush.png");
  theBush->setPos(200,500);
  scene->addItem(theBush);
  theBush = new QGraphicsPixmapItem(imgFolder + "map/bush.png");
  theBush->setPos(1100,550);
  scene->addItem(theBush);

  // Trees
  theTree = new QGraphicsPixmapItem(imgFolder + "map/tree.png");
  theTree->setPos(700,50);
  scene->addItem(theTree);
  theTree = new QGraphicsPixmapItem(imgFolder + "map/tree.png");
  theTree->setPos(350,200);
  scene->addItem(theTree);
  theTree = new QGraphicsPixmapItem(imgFolder + "map/tree.png");
  theTree->setPos(550,525);
  scene->addItem(theTree);

  // Flowers
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(150,250);
  scene->addItem(theFlower);
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(450,50);
  scene->addItem(theFlower);
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(475,500);
  scene->addItem(theFlower);
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(550,450);
  scene->addItem(theFlower);
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(900,200);
  scene->addItem(theFlower);
  theFlower = new QGraphicsPixmapItem(imgFolder + "map/flower.png");
  theFlower->setPos(950,250);
  scene->addItem(theFlower);

  // Left path
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(0,400);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(90,400);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(180,400);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(270,400);
  scene->addItem(thePathWE);
  thePathCorner = new QGraphicsPixmapItem(imgFolder + "map/path_corner_2.png");
  thePathCorner->setPos(360,400);
  scene->addItem(thePathCorner);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(450,580);
  thePathNS->setRotation(180);
  scene->addItem(thePathNS);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(450,670);
  thePathNS->setRotation(180);
  scene->addItem(thePathNS);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(450,760);
  thePathNS->setRotation(180);
  scene->addItem(thePathNS);

  // Right path
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(1190,350);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(1100,350);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(1010,350);
  scene->addItem(thePathWE);
  thePathWE = new QGraphicsPixmapItem(imgFolder + "map/path_we.png");
  thePathWE->setPos(920,350);
  scene->addItem(thePathWE);
  thePathCorner = new QGraphicsPixmapItem(imgFolder + "map/path_corner.png");
  thePathCorner->setPos(830,350);
  scene->addItem(thePathCorner);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(830,440);
  scene->addItem(thePathNS);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(830,530);
  scene->addItem(thePathNS);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(830,620);
  scene->addItem(thePathNS);
  thePathNS = new QGraphicsPixmapItem(imgFolder + "map/path_ns.png");
  thePathNS->setPos(830,710);
  scene->addItem(thePathNS);

  // Water
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(50,50);
  scene->addItem(theWaterCorner);
  theWaterSide = new QGraphicsPixmapItem(imgFolder + "map/water_side.png");
  theWaterSide->setPos(50,82);
  scene->addItem(theWaterSide);
  theWaterSide = new QGraphicsPixmapItem(imgFolder + "map/water_side.png");
  theWaterSide->setPos(50,114);
  scene->addItem(theWaterSide);
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(50,178);
  theWaterCorner->setRotation(-90);
  scene->addItem(theWaterCorner);
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(114,178);
  theWaterCorner->setRotation(180);
  scene->addItem(theWaterCorner);
  theWaterInner = new QGraphicsPixmapItem(imgFolder + "map/water_inner.png");
  theWaterInner->setPos(82,114);
  scene->addItem(theWaterInner);
  theWaterFull = new QGraphicsPixmapItem(imgFolder + "map/water_full.png");
  theWaterFull->setPos(82,82);
  scene->addItem(theWaterFull);
  theWaterInner = new QGraphicsPixmapItem(imgFolder + "map/water_inner.png");
  theWaterInner->setPos(114,82);
  scene->addItem(theWaterInner);
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(146,146);
  theWaterCorner->setRotation(180);
  scene->addItem(theWaterCorner);
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(178,114);
  theWaterCorner->setRotation(180);
  scene->addItem(theWaterCorner);
  theWaterCorner = new QGraphicsPixmapItem(imgFolder + "map/water_corner.png");
  theWaterCorner->setPos(178,50);
  theWaterCorner->setRotation(90);
  scene->addItem(theWaterCorner);
  theWaterSide = new QGraphicsPixmapItem(imgFolder + "map/water_side.png");
  theWaterSide->setPos(114,50);
  theWaterSide->setRotation(90);
  scene->addItem(theWaterSide);
  theWaterSide = new QGraphicsPixmapItem(imgFolder + "map/water_side.png");
  theWaterSide->setPos(146,50);
  theWaterSide->setRotation(90);
  scene->addItem(theWaterSide);

  // Letter Box
  theWaterSide = new QGraphicsPixmapItem(imgFolder + "map/letter_box.png");
  theWaterSide->setPos(1218,261);
  scene->addItem(theWaterSide);

  scene->addItem(ligneLeft);
  scene->addItem(ligneRight);
  scene->addItem(ligneUp);
  scene->addItem(ligneDown);

  view->fitInView(scene->sceneRect());
  view->setScene(scene);
  view->show();
}

void Log::CreatePlayer()
{
  thePlayer = new QGraphicsPixmapItem(imgFolder + "players/A/center.png");
  scene->addItem(thePlayer);
}

void Log::SendCommand(QChar commande)
{
  quint16 taille=0;
  QBuffer tampon;
  tampon.open(QIODevice::WriteOnly);
  QDataStream out(&tampon);
  out<<taille<<commande;
  taille=tampon.size() - sizeof(taille);
  tampon.seek(0);
  out<<taille;
  socketDeDialogueAvecServeur->write(tampon.buffer());
}

void Log::on_pushButton_Connection_clicked()
{
  if(ui->pushButton_Connection->text() == "Log In")
    {
      socketDeDialogueAvecServeur->connectToHost(ui->lineEdit_IP->text(),ui->spinBox_Port->value());
    }
  else if(ui->pushButton_Connection->text() == "Log Out")
    {
      socketDeDialogueAvecServeur->disconnectFromHost();
      move(800,300);
    }
}

void Log::onQTcpSocket_connected()
{
  qDebug()<< this << "connected";
  LogState();
  CreateScene();
  CreatePlayer();
}

void Log::onQTcpSocket_disconnected()
{
  qDebug()<< this << "disconnected";
}

void Log::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
  qDebug() << this << socketDeDialogueAvecServeur->errorString();
}

void Log::onQTcpSocket_hostFound()
{
  qDebug() << this << "host found";
}

void Log::onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState)
{
  QString etat;
  switch (socketState) {
    case QAbstractSocket::UnconnectedState:
      etat = "The socket is not connected.";
      break;
    case QAbstractSocket::HostLookupState:
      etat = "The socket is performing a host name lookup";
      break;
    case QAbstractSocket::ConnectingState:
      etat = "The socket has started establishing a connection";
      break;
    case QAbstractSocket::ConnectedState:
      etat = "A connection is established";
      break;
    case QAbstractSocket::BoundState:
      etat = "The socket is bound to an address and port";
      break;
    case QAbstractSocket::ListeningState:
      etat = "For internal use only";
      break;
    case QAbstractSocket::ClosingState:
      etat = "The socket is about to close";
      break;
    }
  ui->label_State->setText(etat);
  qDebug() << this << etat;
}

void Log::onQTcpSocket_aboutToClose()
{
  qDebug() << this << "about to close";
}

void Log::onQTcpSocket_bytesWritten(qint64 bytes)
{
  qDebug() << this << "bytes written : " << bytes;
}

void Log::onQTcpSocket_readChannelFinished()
{
  qDebug() << this << "read channel finnished";
}

void Log::onQTcpSocket_readyRead()
{
  quint16 taille; // La taille minimale pour prendre en compte les datas
  QPoint position;
  QString message;
  double distance;

  qDebug() << this << "Ready Read : " << QString::number(socketDeDialogueAvecServeur->bytesAvailable()) << " bytes Availables";
  if (socketDeDialogueAvecServeur->bytesAvailable() >= (qint64)sizeof(taille))
    {
      QDataStream in(socketDeDialogueAvecServeur);
      in >> taille;

      if (socketDeDialogueAvecServeur->bytesAvailable() >= (qint64)taille)
        {
          in >> position >> message >> distance;
          qDebug() << this << "Position : " << position;
          qDebug() << this << "Message : " << message;
          qDebug() << this << "Distance : " << distance;

          if (direction=='L')
            {
              thePlayer->setPixmap(QPixmap(imgFolder + "players/A/left.png"));
            }
          if (direction=='R')
            {
              thePlayer->setPixmap(QPixmap(imgFolder + "players/A/right.png"));
            }
          if (direction=='U')
            {
              thePlayer->setPixmap(QPixmap(imgFolder + "players/A/up.png"));
            }
          if (direction=='D')
            {
              thePlayer->setPixmap(QPixmap(imgFolder + "players/A/down.png"));
            }

          if (position != QPoint(-1,-1))
            {
              if (message.contains("collision"))
                {
                  ui->label_State->setStyleSheet("color : magenta; font: bold 18px;");
                }
              thePlayer->setPos(position);
              qDebug() << "Pos : " << position;
            }
          else
            {
              if (message.contains(socketDeDialogueAvecServeur->localAddress().toString()))
                {
                  ui->label_State->setStyleSheet("color : green; font: bold 18px;");
                  distance = 0;
                }
              else
                {
                  ui->label_State->setStyleSheet("color : red; font: bold 18px;");
                }
            }
          ui->label_State->setText(message);
          ui->lcdNumber_Distance->display(distance);
        }
    }
}

void Log::LogState()
{
      ui->pushButton_Connection->setText("Log Out");
      ui->label_State->setText("Connection established");
      ui->label_State->show();
      ui->label_State->setGeometry(100,800,200,30);
      ui->label_Distance->show();
      ui->label_Distance->setGeometry(400,800,100,30);
      ui->lcdNumber_Distance->show();
      ui->lcdNumber_Distance->setGeometry(500,800,100,30);
      ui->lineEdit_Party->show();
      ui->lineEdit_Party->setGeometry(200,800,200,30);
      ui->label_IP->hide();
      ui->lineEdit_IP->hide();
      ui->label_Port->hide();
      ui->spinBox_Port->hide();
}
void Log::keyPressEvent(QKeyEvent *event)
{
  switch(event->key())
    {
    case Qt::Key_Left:
      qDebug() << "Left";
      direction='L';
      SendCommand(direction);
      break;
    case Qt::Key_Right:
      qDebug() << "Right";
      direction='R';
      SendCommand(direction);
      break;
    case Qt::Key_Up:
      qDebug() << "Up";
      direction='U';
      SendCommand(direction);
      break;
    case Qt::Key_Down:
      qDebug() << "Down";
      direction='D';
      SendCommand(direction);
      break;
    }
}

