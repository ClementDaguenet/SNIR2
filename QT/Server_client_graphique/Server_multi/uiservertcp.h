#ifndef UISERVERTCP_H
#define UISERVERTCP_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class UIServerTcp; }
QT_END_NAMESPACE

class UIServerTcp : public QWidget
{
  Q_OBJECT

public:
  UIServerTcp(QWidget *parent = nullptr);
  ~UIServerTcp();

private slots:
  void on_pushButton_Lancer_clicked();
  void onQTcpServerAcceptError(QAbstractSocket::SocketError socketError);
  void onQTcpServerNewConnection();
  void onQTcpSocketConnected();
  void onQTcpSocketDisconnected();
  void onQTcpSocketReadyRead();
  void onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState);
  void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError);
  void onQTcpSocketHostFound();
  void onQTcpSocketAboutToClose();
  void onQTcpSocketBytesWritten(qint64 bytes);
  void onQTcpSocketChannelsBytesWritten(int channel, qint64 bytes);
  void onQTcpSocketChannelReadyRead(int channel);
  void onQTcpSocketReadChannelFinished();

private:
  Ui::UIServerTcp *ui;
  QTcpServer socketServer;
  QList <QTcpSocket *>listeSocketClient;
};
#endif // UISERVERTCP_H
