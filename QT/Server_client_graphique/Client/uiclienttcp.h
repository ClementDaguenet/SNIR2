#ifndef UICLIENTTCP_H
#define UICLIENTTCP_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class UIClientTcp; }
QT_END_NAMESPACE

class UIClientTcp : public QWidget
{
  Q_OBJECT

  public:
    UIClientTcp(QWidget *parent = nullptr);
    ~UIClientTcp();

  private slots:
    void on_pushButton_Connexion_clicked();
    void on_pushButton_Envoyer_clicked();
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
    Ui::UIClientTcp *ui;
    QTcpSocket sockVersServeur;
};
#endif // UICLIENTTCP_H
