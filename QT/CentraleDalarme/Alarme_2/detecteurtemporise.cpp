#include "detecteurtemporise.h"

DetecteurTemporise::DetecteurTemporise()
{
  setWindowTitle("Détecteur Temporisé");
  timerDetecteur.start(3000);
  QMessageBox messagePresence;
  messagePresence.setText("Intrus détecté");
}

void DetecteurTemporise::on_pushButton_Intrus_clicked()
{

}

