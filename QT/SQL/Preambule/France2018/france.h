#ifndef FRANCE_H
#define FRANCE_H

#include <QWidget>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class France; }
QT_END_NAMESPACE

class France : public QWidget
{
  Q_OBJECT

public:
  France(QWidget *parent = nullptr);
  ~France();

private slots:
  void on_pushButton_Connexion_clicked();

  void on_pushButton_Nom_clicked();

private:
  Ui::France *ui;
  QSqlDatabase bd;
};
#endif // FRANCE_H
