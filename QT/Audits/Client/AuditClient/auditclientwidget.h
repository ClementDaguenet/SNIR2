#ifndef AUDITCLIENTWIDGET_H
#define AUDITCLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>
#include <QAuthenticator>

QT_BEGIN_NAMESPACE
namespace Ui { class AuditClientWidget; }
QT_END_NAMESPACE

class AuditClientWidget : public QWidget
{
  Q_OBJECT

public:
  AuditClientWidget(QWidget *parent = nullptr);
  ~AuditClientWidget();

private:
  Ui::AuditClientWidget *ui;
  QTcpSocket *socketDeDialogueAvecServeur;
  QString typeDeDemande;

private slots:
  void on_pushButton_Connexion_clicked();
  void on_pushButton_Name_clicked();
  void on_pushButton_User_clicked();
  void on_pushButton_Archi_clicked();
  void on_pushButton_OS_clicked();

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
};
#endif // AUDITCLIENTWIDGET_H
