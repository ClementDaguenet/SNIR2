#ifndef BANQUEWIDGET_H
#define BANQUEWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QSettings>
#include <QMessageBox>
#include "ajoutdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BanqueWidget; }
QT_END_NAMESPACE

class BanqueWidget : public QWidget
{
  Q_OBJECT

public:
  BanqueWidget(QWidget *parent = nullptr);
  ~BanqueWidget();

private slots:
  void on_pushButton_Connexion_clicked();

  void on_pushButton_Informations_clicked();

  void on_pushButton_Ajouter_clicked();

private:
  Ui::BanqueWidget *ui;
  QSqlDatabase bd;
};
#endif // BANQUEWIDGET_H
