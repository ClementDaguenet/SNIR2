#ifndef SERVEURWEB_H
#define SERVEURWEB_H

#include <QWidget>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#define TEMPO_DATE 2000

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurWeb; }
QT_END_NAMESPACE

class ServeurWeb : public QWidget
{
  Q_OBJECT

public:
  ServeurWeb(QWidget *parent = nullptr);
  ~ServeurWeb();

private slots:
  void on_pushButton_Lancer_clicked();
  void onQWebSocketServer_newConnection();
  void onQWebSocket_textMessageReceived(QString _message);
  void onTimerDate_timeout();

private:
  Ui::ServeurWeb *ui;
  QTimer *timerDate;
  QWebSocket *socketClient;
  QWebSocketServer *socketServeur;
};
#endif // SERVEURWEB_H
