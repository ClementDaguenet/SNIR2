#ifndef CLAVIER_H
#define CLAVIER_H

#include "detecteurtemporise.h"
#include "centraledalarme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Clavier; }
QT_END_NAMESPACE

class Clavier : public QWidget
{
  Q_OBJECT

public:
  Clavier(CentraleDalarme *_laCentrale, QWidget *parent = nullptr);
  ~Clavier();
  void LancerTempo();
  void TraiterChiffre();

private slots:
  void onTimerLed_timeout();
  void on_pushButton_Marche_pressed();
  void on_pushButton_Marche_released();

public slots:
  void onEtatCentraleChange(const CentraleDalarme::MODES_DE_MARCHE _etat);

private:
  Ui::Clavier *ui;
  QTimer timerClavier;
  QTimer timerLed;
  CentraleDalarme::MODES_DE_MARCHE etatCentrale;
  CentraleDalarme *laCentrale;
};

#endif // CLAVIER_H
