#ifndef AJOUTDIALOG_H
#define AJOUTDIALOG_H

#include <QWidget>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QSettings>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
  class AjoutDialog;
}

class AjoutDialog : public QDialog
{
  Q_OBJECT

public:
  explicit AjoutDialog(QWidget *parent = nullptr);
  ~AjoutDialog();
  int ObtenirIdCompte();
  QString ObtenirNom();
  QString ObtenirPrenom();
  float ObtenirSolde();
  int ObtenirIdAgence();
  QString ObtenirVille();

private:
  Ui::AjoutDialog *ui;
};

#endif // AJOUTDIALOG_H
