#include "detecteur.h"
#include "ui_detecteur.h"

Detecteur::Detecteur(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Detecteur)
{
  ui->setupUi(this);
}

Detecteur::~Detecteur()
{
  delete ui;
}

void Detecteur::on_pushButton_Intrus_clicked()
{
  emit intrusDetecte();
}

