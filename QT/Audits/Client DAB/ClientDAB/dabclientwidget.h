#ifndef DABCLIENTWIDGET_H
#define DABCLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class DabClientWidget; }
QT_END_NAMESPACE

class DabClientWidget : public QWidget
{
  Q_OBJECT

public:
  DabClientWidget(QWidget *parent = nullptr);
  ~DabClientWidget();

private slots:
  void on_pushButton_Connexion_clicked();
  void on_pushButton_Numero_clicked();
  void on_pushButton_Envoi_clicked();

  void onQTcpSocketConnected();
  void onQTcpSocketDisconnected();
  void onQTcpSocketReadyRead();
  void onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState);
  void onQTcpSocketErrorOccurred(QAbstractSocket::SocketError socketError);
  void onQTcpSocketHostFound();
  void onQTcpSocketAboutToClose();
  void onQTcpSocketBytesWritten(qint64 bytes);

private:
  Ui::DabClientWidget *ui;
  QTcpSocket socketClientBanque;
};

#endif // DABCLIENTWIDGET_H
