#ifndef CATSERVEUR_H
#define CATSERVEUR_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

#define TAILLE_X 1280
#define TAILLE_Y 724

namespace Ui {
  class CATServeur;
}

class CATServeur : public QWidget
{
  Q_OBJECT

public:
  explicit CATServeur(QWidget *parent = nullptr);
  ~CATServeur();
  void ShowScene();
  void PlaceTreasure(QPoint pt);
  void CreatePlayer(QPoint pt);
  void ChangePlayerPosition(int indexClient, QPoint pos);
  QPointF GetTreasurePosition();
  void ChangePlayerDirection(int indexClient, QString direction);
  void OpenTreasure(QString state);

private:
  Ui::CATServeur *ui;
  QGridLayout *grille;
  QGraphicsScene *scene;
  QGraphicsView *view;
  QString musicFolder;
  QString imgFolder;
  QList <QGraphicsPixmapItem *>thePlayers;
  QBrush fontPlayer;
  QPixmap player;

  QGraphicsPixmapItem *theMap;
  QGraphicsPixmapItem *theHouse;
  QGraphicsPixmapItem *theTreasure;
  QGraphicsPixmapItem *theTree;
  QGraphicsPixmapItem *theBush;
  QGraphicsPixmapItem *theFlower;
  QGraphicsPixmapItem *theWaterFull;
  QGraphicsPixmapItem *theWaterSide;
  QGraphicsPixmapItem *theWaterCorner;
  QGraphicsPixmapItem *theWaterInner;
  QGraphicsPixmapItem *theLetterBox;
  QGraphicsPixmapItem *thePathCorner;
  QGraphicsPixmapItem *thePathNS;
  QGraphicsPixmapItem *thePathWE;

  void advance(int step);
};

#endif // CATSERVEUR_H
