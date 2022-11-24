#ifndef DETECTEUR_H
#define DETECTEUR_H

#include <QDialog>
#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>

namespace Ui { class Detecteur; }

class Detecteur : public QDialog
{
  Q_OBJECT

public:
  explicit Detecteur(QWidget *parent = nullptr);
  ~Detecteur();

protected:
  Ui::Detecteur *ui;

private slots:
  void on_pushButton_Intrus_clicked();

signals:
  void intrusDetecte();
};

#endif // DETECTEUR_H
