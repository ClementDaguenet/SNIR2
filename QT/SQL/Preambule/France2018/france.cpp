#include "france.h"
#include "ui_france.h"

France::France(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::France)
{
  ui->setupUi(this);
  ui->lineEdit_Nom->setDisabled(true);
  ui->lineEdit_Resultat->setDisabled(true);
  ui->pushButton_Nom->setDisabled(true);

  // ajouts des items dans la combo box region
  QSqlQuery requeteRegions("select code, name from regions order by name;" );
  if (!requeteRegions.exec()){
      qDebug() << "Error query regions" << requeteRegions.lastError();
    }
  QString nomRegions, idRegions;
  while(requeteRegions.next())
    {
      nomRegions = requeteRegions.value("name").toString();
      idRegions = requeteRegions.value("code").toString();
      ui->comboBox_Regions->addItem(nomRegions,idRegions);
    }

//  // ajouts des items dans la combo box departement
//  QSqlQuery requeteDepartements("select code, name from departments order by name;" );
//  if (!requeteDepartements.exec()){
//      qDebug() << "Error query departments" << requeteDepartements.lastError();
//    }
//  QString nomDepartements, idDepartements;
//  while(requeteDepartements.next())
//    {
//      nomDepartements = requeteDepartements.value("name").toString();
//      idDepartements = requeteDepartements.value("code").toString();
//      ui->comboBox_Departements->addItem(nomDepartements,idDepartements);
//    }

//  // ajouts des items dans la combo box ville
//  QSqlQuery requeteVilles("select id, name from cities order by name;" );
//  if (!requeteVilles.exec()){
//      qDebug() << "Error query cities" << requeteVilles.lastError();
//    }
//  QString nomVilles, idVilles;
//  while(requeteVilles.next())
//    {
//      nomVilles = requeteVilles.value("name").toString();
//      idVilles = requeteVilles.value("id").toString();
//      ui->comboBox_Villes->addItem(nomVilles,idVilles);
//    }
}

France::~France()
{
  delete ui;
}

void France::on_pushButton_Connexion_clicked()
{
  bd = QSqlDatabase::addDatabase("QMYSQL");
  QFileInfo conf("../France2018/confbdd.ini");
  if(conf.exists() && conf.isFile())
    {
      QSettings params("../France2018/confbdd.ini",QSettings::IniFormat);
        bd.setHostName(params.value("confBdd/host").toString());
        bd.setDatabaseName(params.value("confBdd/db").toString());
        bd.setUserName(params.value("confBdd/user").toString());
        bd.setPassword(params.value("confBdd/pwd").toString());
    }
  if (!bd.open())
    {
      qDebug() << bd.lastError().text();
    }
  else
    {
      qDebug() << "Successful access on" << bd.databaseName();
      ui->pushButton_Connexion->setDisabled(true);
      ui->pushButton_Connexion->setStyleSheet("background-color: #151515; font-size: 12px; color: #808080; font-weight: bold;");
      ui->lineEdit_Nom->setDisabled(false);
      ui->lineEdit_Nom->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
      ui->lineEdit_Resultat->setDisabled(false);
      ui->pushButton_Nom->setDisabled(false);
      ui->pushButton_Nom->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
      ui->label_Nom->setDisabled(false);
      ui->label_Nom->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
      ui->comboBox_Regions->setDisabled(false);
      ui->comboBox_Regions->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
      ui->comboBox_Departements->setDisabled(false);
      ui->comboBox_Departements->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
      ui->comboBox_Villes->setDisabled(false);
      ui->comboBox_Villes->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
    }
}

void France::on_pushButton_Nom_clicked()
{
  ui->lineEdit_Resultat->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
  QSqlQuery requete;
  requete.prepare("select name from departments where code like :numDepartment; ");
  requete.bindValue(":numDepartment",ui->lineEdit_Nom->text());
  if (!requete.exec())
    {
      qDebug() << requete.lastError().text();
    }
  while(requete.next())
    {
      QString nomDepartement = requete.value("name").toString();
      ui->lineEdit_Resultat->setText(nomDepartement);
    }
}

