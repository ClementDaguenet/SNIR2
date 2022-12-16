#ifndef LOG_H
#define LOG_H

#include "catserveur.h"
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QGridLayout>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QToolButton>
#include <QRandomGenerator>
#include <QDateTime>
#include <QThread>
#include <QTimer>
#include <QBuffer>

namespace Ui {
  class Log;
}

class Log : public QWidget
{
  Q_OBJECT

public:
  explicit Log(QWidget *parent = nullptr);
  ~Log();

private slots:
    void on_pushButton_Start_clicked();
    void onQTcpServer_newConnection();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_disconnected();

private:
  void LogState(const QString _state);
  void SendData(QTcpSocket *client,QPoint pt, QString msg);
  QPoint GiveUniquePosition();
  double CalculcateDistance(QPoint _position);
  void Wait(int _milliseconds);
  void closeEvent(QCloseEvent *event) override;

  Ui::Log *ui;
  CATServeur *CATScene;
  QTcpServer *socketEcoute;
  QList <QTcpSocket *>listeSocketsClient;
  QList <QPoint>listePositions;
  int nbPlayers;
};

#endif // LOG_H
