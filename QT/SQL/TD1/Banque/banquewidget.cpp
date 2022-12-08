#include "banquewidget.h"
#include "ui_banquewidget.h"

BanqueWidget::BanqueWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::BanqueWidget)
{
  ui->setupUi(this);
  setWindowTitle("La Banque des SNIR");
  ui->groupBox_Informations->setDisabled(true);
  ui->pushButton_Ajouter->setDisabled(true);
  ui->textEdit_Informations->hide();
  ui->tableWidget_Informations->show();
  QHeaderView *headers = ui->tableWidget_Informations->horizontalHeader();
  headers->setSectionResizeMode(QHeaderView::Stretch);
}

BanqueWidget::~BanqueWidget()
{
  delete ui;
}

void BanqueWidget::on_pushButton_Connexion_clicked()
{
  ui->pushButton_Connexion->setDisabled(true);
  ui->pushButton_Connexion->setStyleSheet("background-color: #151515; font-size: 24px; color: #808080; font-weight: bold;");
  ui->groupBox_Informations->setDisabled(false);
  ui->groupBox_Informations->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
  ui->pushButton_Informations->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
  ui->textEdit_Informations->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
  ui->tableWidget_Informations->setStyleSheet("background-color: #151515; font-size: 12px; color: #fff; font-weight: bold;");
  ui->pushButton_Ajouter->setDisabled(false);
  ui->pushButton_Ajouter->setStyleSheet("background-color: #151515; font-size: 24px; color: #fff; font-weight: bold;");
  ui->pushButton_Connexion->setText("Connecté");
  bd = QSqlDatabase::addDatabase("QMYSQL");
  QFileInfo conf("../Banque/confbdd.ini");
  if(conf.exists() && conf.isFile())
    {
      QSettings params("../Banque/confbdd.ini",QSettings::IniFormat);
      QString host = params.value("confBdd/host").toString();
      bd.setHostName(host);
      bd.setDatabaseName(params.value("confBdd/db").toString());
      bd.setUserName(params.value("confBdd/user").toString());
      bd.setPassword(params.value("confBdd/pwd").toString());
    }
  if (!bd.open())
    {
      QMessageBox boxErreur;
      boxErreur.setText(bd.lastError().text());
      boxErreur.exec();
    }
  else
    {
      qDebug() << "Successful access on" << bd.databaseName();
    }
}

void BanqueWidget::on_pushButton_Informations_clicked()
{
  qDebug() << "Visualisation clients";
  QSqlQuery requeteAgence("select idCompte, solde, comptes.nom, prenom, agences.nom, agences.Ville from comptes, agences where comptes.id_agence = agences.id;" );
  if (!requeteAgence.exec()){
      qDebug() << "Error query agence" << requeteAgence.lastError();
    }
  QString idCompte, nom, prenom, solde, nomAgence, villeAgence;
  int ligne = 0;
  while(requeteAgence.next())
    {
      int col = 0;
      idCompte = requeteAgence.value("idCompte").toString();
      nom = requeteAgence.value("nom").toString();
      prenom = requeteAgence.value("prenom").toString();
      solde = requeteAgence.value("solde").toString();
      nomAgence = requeteAgence.value("agences.nom").toString();
      villeAgence = requeteAgence.value("agences.Ville").toString();
      ui->tableWidget_Informations->insertRow(ui->tableWidget_Informations->rowCount());
      QTableWidgetItem *idCompteItem = new QTableWidgetItem(idCompte);
      ui->tableWidget_Informations->setItem(ligne,col++,idCompteItem);
      QTableWidgetItem *nomItem = new QTableWidgetItem(nom);
      ui->tableWidget_Informations->setItem(ligne,col++,nomItem);
      QTableWidgetItem *prenomItem = new QTableWidgetItem(prenom);
      ui->tableWidget_Informations->setItem(ligne,col++,prenomItem);;
      QTableWidgetItem *soldeItem = new QTableWidgetItem(solde);
      ui->tableWidget_Informations->setItem(ligne,col++,soldeItem);
      QTableWidgetItem *nomAgenceItem = new QTableWidgetItem(nomAgence);
      ui->tableWidget_Informations->setItem(ligne,col++,nomAgenceItem);
      QTableWidgetItem *villeAgenceItem = new QTableWidgetItem(villeAgence);
      ui->tableWidget_Informations->setItem(ligne,col++,villeAgenceItem);
      ligne++;
    }
}

void BanqueWidget::on_pushButton_Ajouter_clicked()
{
  AjoutDialog ajoutClient;
  int idCompte;
  qDebug() << "Ajout client";
  if(ajoutClient.exec() == QDialog::Accepted)
    {
      QSqlQuery requeteAjout;
      requeteAjout.prepare("insert into comptes (idCompte, nom, prenom, solde, ville, id_agence) values (':idCompte',':nom',':prenom',':solde',':ville',':idAgence');");
      idCompte = ajoutClient.ObtenirIdCompte();
      requeteAjout.bindValue(":idCompte",idCompte);
      qDebug() << idCompte;
      requeteAjout.bindValue(":nom",ajoutClient.ObtenirNom());
      requeteAjout.bindValue(":prenom",ajoutClient.ObtenirPrenom());
      requeteAjout.bindValue(":solde",ajoutClient.ObtenirSolde());
      requeteAjout.bindValue(":ville",ajoutClient.ObtenirVille());
      requeteAjout.bindValue(":idAgence",ajoutClient.ObtenirIdAgence());
      if (!requeteAjout.exec()){
          qDebug() << "Error query add" << requeteAjout.lastError();
        }
    }
}

