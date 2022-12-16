#ifndef LOG_H
#define LOG_H

#include <QWidget>
#include <QTcpSocket>
#include <QGridLayout>
#include <QToolButton>
#include <QBuffer>
#include <QHostAddress>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class Log;
}

class Log : public QWidget
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = nullptr);
    ~Log();
  void CreateScene();
  void CreatePlayer();
  void SendCommand(QChar commande);

private slots:
    void on_pushButton_Connection_clicked();
    void onQTcpSocket_connected ();
    void onQTcpSocket_disconnected ();
    void onQTcpSocket_error ( QAbstractSocket::SocketError socketError );
    void onQTcpSocket_hostFound ();
    void onQTcpSocket_stateChanged ( QAbstractSocket::SocketState socketState );
    void onQTcpSocket_aboutToClose ();
    void onQTcpSocket_bytesWritten ( qint64 bytes );
    void onQTcpSocket_readChannelFinished ();
    void onQTcpSocket_readyRead ();

private:
    Ui::Log *ui;
    QTcpSocket *socketDeDialogueAvecServeur;
    void LogState();
    void keyPressEvent(QKeyEvent *event) override;
    QMediaPlayer *soundPlayer;
    QAudioOutput *audioOutput;
    QString imgFolder;
    QString musicFolder;
    QString desactivate;
    QString activate;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QChar direction;

    QGraphicsPixmapItem *thePlayer;
    QGraphicsPixmapItem *theMap;
    QGraphicsPixmapItem *theHouse;
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
};

#endif // LOG_H
