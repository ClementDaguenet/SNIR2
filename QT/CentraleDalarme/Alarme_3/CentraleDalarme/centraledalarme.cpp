#include "centraledalarme.h"
#include "clavier.h"

CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *parent):
  QObject{parent},
  tailleCode(_tailleCode)
{
  leClavier = new Clavier(this);
  leCode = new Code(tailleCode);
  leDetecteur = new Detecteur();
  leDetecteurTempo = new DetecteurTemporise();
  laSirene = new Sirene();
  leClavier->show();
}

CentraleDalarme::~CentraleDalarme()
{
  delete leClavier;
  delete leCode;
  delete leDetecteur;
  delete leDetecteurTempo;
  delete laSirene;
}

void CentraleDalarme::ModifierCode()
{
  if(indiceCourant == tailleCode)
    {
      mode = MODIFICATION_CODE;
      emit EtatCentraleChange(mode);
    }
}

void CentraleDalarme::TraiterBoutonMarche()
{
  mode = SURVEILLANCE;
  emit EtatCentraleChange(mode);
}

void CentraleDalarme::FabriquerCode()
{
  mode = SAISIE_NOUVEAU;
  emit EtatCentraleChange(mode);
}

void CentraleDalarme::Activer()
{
  mode = ACTIVATION;
  emit EtatCentraleChange(mode);
}

void CentraleDalarme::Desactiver()
{
  mode = DESACTIVATION;
  emit EtatCentraleChange(mode);
}

void CentraleDalarme::TraiterBoutonArret()
{
  mode = REPOS;
  emit EtatCentraleChange(mode);
}

void CentraleDalarme::onTimerDelai_timeout()
{

}

void CentraleDalarme::onIntrusDetecte()
{
  laSirene->Enclencher();
}
