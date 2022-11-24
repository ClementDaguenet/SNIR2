#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
  DetecteurTemporise();
  ~DetecteurTemporise();
  void LancerTempo();

private slots:
  void onTimerIntrus_timeout();

private:
  QTimer timerIntrus;
};

#endif // DETECTEURTEMPORISE_H
