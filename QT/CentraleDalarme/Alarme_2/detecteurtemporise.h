#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
  DetecteurTemporise();

private slots:
  void on_pushButton_Intrus_clicked();

private:
  QTimer timerDetecteur;
};

#endif // DETECTEURTEMPORISE_H
