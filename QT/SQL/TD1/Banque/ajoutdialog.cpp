#include "ajoutdialog.h"
#include "ui_ajoutdialog.h"

AjoutDialog::AjoutDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AjoutDialog)
{
  ui->setupUi(this);
  setWindowTitle("Création d'un client");
  ui->comboBox_Agence->addItem("Choisir une agence","-1");
  QSqlQuery requete("select id, nom from agences;" );
  if (!requete.exec()){
      qDebug() << "Error query" << requete.lastError();
    }
  QString nom;
  QString id;
  while(requete.next())
    {
      nom = requete.value("nom").toString();
      id = requete.value("id").toString();
      ui->comboBox_Agence->addItem(nom,id);
    }
}

AjoutDialog::~AjoutDialog()
{
  delete ui;
}

int AjoutDialog::ObtenirIdCompte()
{
  return ui->lineEdit_Numero->text().toInt();
}

QString AjoutDialog::ObtenirNom()
{
  return ui->lineEdit_Nom->text();
}

QString AjoutDialog::ObtenirPrenom()
{
  return ui->lineEdit_Prenom->text();
}

float AjoutDialog::ObtenirSolde()
{
  return ui->lineEdit_Solde->text().toFloat();
}

int AjoutDialog::ObtenirIdAgence()
{
  return ui->comboBox_Agence->currentData().toInt();
}

QString AjoutDialog::ObtenirVille()
{
  return ui->lineEdit_Ville->text();
}
