#include "catserveur.h"
#include "ui_catserveur.h"

CATServeur::CATServeur(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CATServeur)
{
  ui->setupUi(this);
  setFocus();
  setWindowTitle("Chasse Au Trésor Serveur");
  imgFolder = "../img/";
  musicFolder = "../sounds/";
  ShowScene();
}

CATServeur::~CATServeur()
{
  delete ui;
}

void CATServeur::ShowScene()
{
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

  theTreasure = new QGraphicsPixmapItem(imgFolder + "map/treasure.png");
  scene->addItem(theTreasure);

  scene->addItem(ligneLeft);
  scene->addItem(ligneRight);
  scene->addItem(ligneUp);
  scene->addItem(ligneDown);

  view->fitInView(scene->sceneRect());
  view->setScene(scene);
  view->show();
}

void CATServeur::PlaceTreasure(QPoint pt)
{
  theTreasure->setPos(pt);
}

void CATServeur::CreatePlayer(QPoint pt)
{
  QGraphicsPixmapItem *thePlayer = new QGraphicsPixmapItem(imgFolder + "players/A/center.png");
  thePlayer->setPos(pt);
  qDebug() << "Pos create : " << pt;
  thePlayers.append(thePlayer);
  scene->addItem(thePlayer);
}

void CATServeur::ChangePlayerPosition(int indexClient, QPoint pos)
{
  thePlayers.at(indexClient)->setPos(pos);
}

QPointF CATServeur::GetTreasurePosition()
{
  return theTreasure->pos();
}

void CATServeur::ChangePlayerDirection(int indexClient, QString direction)
{
  if (direction=="left")
    {
      thePlayers.at(indexClient)->setPixmap(QPixmap(imgFolder + "players/A/left.png"));
    }
  if (direction=="right")
    {
      thePlayers.at(indexClient)->setPixmap(QPixmap(imgFolder + "players/A/right.png"));
    }
  if (direction=="up")
    {
      thePlayers.at(indexClient)->setPixmap(QPixmap(imgFolder + "players/A/up.png"));
    }
  if (direction=="down")
    {
      thePlayers.at(indexClient)->setPixmap(QPixmap(imgFolder + "players/A/down.png"));
    }
}

void CATServeur::OpenTreasure(QString state)
{
  if(state == "open")
    {
      theTreasure->setPixmap(QPixmap(imgFolder + "map/treasure_open.png"));
    }
  else if(state == "close")
    {
      theTreasure->setPixmap(QPixmap(imgFolder + "map/treasure.png"));
    }
}
