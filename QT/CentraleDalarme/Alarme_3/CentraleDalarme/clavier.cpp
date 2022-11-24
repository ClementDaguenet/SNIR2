#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(CentraleDalarme *_laCentrale, QWidget *parent):
  QWidget(parent),
  ui(new Ui::Clavier),
  laCentrale(_laCentrale)
{
  ui->setupUi(this);
  connect(laCentrale,&CentraleDalarme::EtatCentraleChange,this,&Clavier::onEtatCentraleChange);
  connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
  connect(ui->pushButton_0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
  connect(ui->pushButton_9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
}

Clavier::~Clavier()
{
  delete ui;
}

void Clavier::LancerTempo()
{

}

void Clavier::TraiterChiffre()
{
  QPushButton *pbouton = static_cast<QPushButton *>(sender());
  QString texteBouton = pbouton->text();
//  ui->lineEdit_Code->clear();
  ui->lineEdit_Code->setStyleSheet("QLineEdit{color:#000000;}");
  ui->lineEdit_Code->insert("•");
  laCentrale->FabriquerCode();
}

void Clavier::onTimerLed_timeout()
{
  switch(etatCentrale)
    {
    case CentraleDalarme::ACTIVATION:
      if(ui->checkBox_LedVerte->checkState() == Qt::Checked)
        ui->checkBox_LedVerte->setCheckState(Qt::Unchecked);
      else
        ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      break;
    case CentraleDalarme::DESACTIVATION:
      if(ui->checkBox_LedVerte->checkState() == Qt::Checked)
        ui->checkBox_LedVerte->setCheckState(Qt::Unchecked);
      else
        ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      break;
    case CentraleDalarme::MODIFICATION_CODE:
      if(ui->checkBox_LedVerte->checkState() == Qt::Checked)
        ui->checkBox_LedVerte->setCheckState(Qt::Unchecked);
      else
        ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      if(ui->checkBox_LedRouge->checkState() == Qt::Checked)
        ui->checkBox_LedRouge->setCheckState(Qt::Unchecked);
      else
        ui->checkBox_LedRouge->setCheckState(Qt::Checked);
      break;
    case CentraleDalarme::REPOS:
      break;
    case CentraleDalarme::SAISIE_NOUVEAU:
      break;
    case CentraleDalarme::SURVEILLANCE:
      break;
    }

}

void Clavier::onEtatCentraleChange(const CentraleDalarme::MODES_DE_MARCHE _etat)
{
  etatCentrale = _etat;
  switch(_etat)
    {
    case CentraleDalarme::ACTIVATION:
      // LED VERTE clignote
      ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      timerLed.start(250);
      break;
    case CentraleDalarme::DESACTIVATION:
      // LED VERTE clignote
      ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      timerLed.start(250);
      break;
    case CentraleDalarme::MODIFICATION_CODE:
      // LED VERTE & LED ROUGE clignotent*/
      timerLed.start(500);
      ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      ui->checkBox_LedRouge->setCheckState(Qt::Checked);
      break;
    case CentraleDalarme::REPOS:
      // LED ROUGE constante
      ui->checkBox_LedRouge->setCheckState(Qt::Checked);
      ui->checkBox_LedVerte->setCheckState(Qt::Unchecked);
      timerLed.stop();
      break;
    case CentraleDalarme::SAISIE_NOUVEAU:
      // LED VERTE & LED ROUGE constantes
      ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      ui->checkBox_LedRouge->setCheckState(Qt::Checked);
      break;
    case CentraleDalarme::SURVEILLANCE:
      // LED VERTE constante
      ui->checkBox_LedVerte->setCheckState(Qt::Checked);
      break;
    }
}

void Clavier::on_pushButton_Marche_pressed()
{
  timerClavier.start(20000);
  ui->lineEdit_Valide->setText("Mise en Marche");
}

void Clavier::on_pushButton_Marche_released()
{
  if (timerClavier.remainingTime() <= 15000)
    {
      ui->lineEdit_Valide->setText("Modification Code");
    }
  timerClavier.stop();
}

