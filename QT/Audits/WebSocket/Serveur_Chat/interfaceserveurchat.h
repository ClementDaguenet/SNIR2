#ifndef INTERFACESERVEURCHAT_H
#define INTERFACESERVEURCHAT_H

#include <QWidget>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QDebug>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceServeurChat; }
QT_END_NAMESPACE

class InterfaceServeurChat : public QWidget
{
  Q_OBJECT

public:
  InterfaceServeurChat(QWidget *parent = nullptr);
  ~InterfaceServeurChat();
  void BroadcastMessage(QString _message);

private slots:
  void on_pushButton_Lancer_clicked();
  void onQWebSocketServer_newConnection();
  void onQWebSocket_textMessageReceived(const QString &_message);
  void onQWebSocket_disconnected();

  void on_pushButton_Envoyer_clicked();

private:
  Ui::InterfaceServeurChat *ui;
  QList <QWebSocket *>listeClients;
  QWebSocketServer *socketServeur;
};
#endif // INTERFACESERVEURCHAT_H
