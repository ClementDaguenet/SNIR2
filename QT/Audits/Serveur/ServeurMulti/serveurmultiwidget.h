#ifndef SERVEURMULTIWIDGET_H
#define SERVEURMULTIWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QProcess>
#include <QHostInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurMultiWidget; }
QT_END_NAMESPACE

class ServeurMultiWidget : public QWidget
{
  Q_OBJECT

public:
  ServeurMultiWidget(QWidget *parent = nullptr);
  ~ServeurMultiWidget();

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
  void onQProcessReadyReadStandardOutput();

private:
  Ui::ServeurMultiWidget *ui;
  QTcpServer *socketEcouteServeur;
  QList <QTcpSocket *>listeSocketsDialogueClient;
  QList <QProcess *>listeProcess;

signals:
  void readyReadStandardOutput();
};
#endif // SERVEURMULTIWIDGET_H
