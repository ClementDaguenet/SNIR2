#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent):
  QWidget(parent),
  ui(new Ui::Clavier),
  leDetecteur(nullptr),
  leDetecteurTemporise(nullptr)
{
  ui->setupUi(this);
  connect(ui->pushButton_0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  //  connect(ui->pushButton_2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  //  connect(ui->pushButton_3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  //  connect(ui->pushButton_4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  //  connect(ui->pushButton_5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
}

Clavier::~Clavier()
{
  delete ui;
}

void Clavier::on_pushButton_Marche_clicked()
{
  //  QString texteBouton = ui->pushButton_Marche->text();
  //  QMessageBox messageMarche;
  //  messageMarche.setText("J'ai appuyé sur la touche " + texteBouton);
  //  messageMarche.exec();
  timerLed.start(500);
}

void Clavier::on_pushButton_Arret_clicked()
{
  //  QString texteBouton = ui->pushButton_Arret->text();
  //  QMessageBox messageArret;
  //  messageArret.setText("J'ai appuyé sur la touche " + texteBouton);
  //  messageArret.exec();
  timerLed.stop();
}

void Clavier::TraiterChiffre()
{
  QPushButton *pbouton = static_cast<QPushButton *>(sender());
  QString texteBouton = pbouton->text();
  QMessageBox messageChiffre;
  messageChiffre.setText("J'ai appuyé sur la touche " + texteBouton);
  messageChiffre.exec();
}

void Clavier::onTimerLed_timeout()
{
  if(ui->checkBox_LedRouge->checkState() == Qt::Checked)
    ui->checkBox_LedRouge->setCheckState(Qt::Unchecked);
  else
    ui->checkBox_LedRouge->setCheckState(Qt::Checked);
}

void Clavier::on_pushButton_2_clicked()
{
  if(leDetecteur == nullptr)
    {
      leDetecteur = new Detecteur;
    }
  leDetecteur->show();
}

void Clavier::on_pushButton_3_clicked()
{
  if(leDetecteur != nullptr)
    {
      leDetecteur->hide();
      delete leDetecteur;
      leDetecteur = nullptr;
    }
}

//void Clavier::on_pushButton_4_clicked()
//{
//  if(leDetecteurTemporise == nullptr)
//    {
//      leDetecteurTemporise = new DetecteurTemporise;
//    }
//  leDetecteurTemporise->show();
//}

//void Clavier::on_pushButton_5_clicked()
//{
//  if(DetecteurTemporise != nullptr)
//    {
//      leDetecteurTemporise->hide();
//      delete leDetecteurTemporise;
//      leDetecteurTemporise = nullptr;
//    }
//}
