#ifndef SERVEURMONOWIDGET_H
#define SERVEURMONOWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QProcess>
#include <QHostInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurMonoWidget; }
QT_END_NAMESPACE

class ServeurMonoWidget : public QWidget
{
  Q_OBJECT

public:
  ServeurMonoWidget(QWidget *parent = nullptr);
  ~ServeurMonoWidget();

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
  Ui::ServeurMonoWidget *ui;
  QTcpServer *socketEcouteServeur;
  QTcpSocket *socketDialogueClient;
  QProcess *process;

signals:
  void readyReadStandardOutput();
};
#endif // SERVEURMONOWIDGET_H
