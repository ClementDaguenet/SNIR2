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
};

#endif // DETECTEUR_H
