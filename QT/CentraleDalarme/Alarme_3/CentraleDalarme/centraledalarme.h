#ifndef CENTRALEDALARME_H
#define CENTRALEDALARME_H

#include <QTimer>
#include <QObject>
#include "code.h"
#include "sirene.h"
#include "detecteurtemporise.h"

class Clavier;

class CentraleDalarme : public QObject
{
  Q_OBJECT
public:
  enum MODES_DE_MARCHE
  {
    REPOS = 1,
    MODIFICATION_CODE,
    SAISIE_NOUVEAU,
    SURVEILLANCE,
    ACTIVATION,
    DESACTIVATION
  };
  explicit CentraleDalarme(const int _tailleCode, QObject *parent = nullptr);
  ~CentraleDalarme();
  void ModifierCode();
  void TraiterBoutonMarche();
  void FabriquerCode();
  void Activer();
  void Desactiver();
  void TraiterBoutonArret();

private slots:
  void onTimerDelai_timeout();
  void onIntrusDetecte();

private:
  QTimer timerDelai;
  Clavier *leClavier;
  Detecteur *leDetecteur;
  DetecteurTemporise *leDetecteurTempo;
  Code *leCode;
  Sirene *laSirene;

  MODES_DE_MARCHE mode;
  quint8 *combinaison;
  int indiceCourant;
  int tailleCode;

signals:
  void EtatCentraleChange(MODES_DE_MARCHE _nouvelEtat);
};

#endif // CENTRALEDALARME_H
