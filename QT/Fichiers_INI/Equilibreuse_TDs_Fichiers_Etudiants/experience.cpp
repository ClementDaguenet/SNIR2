#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include "experience.h"

Experience::Experience(QObject *parent) : QObject(parent)
, vitesseMaxi(0)
, nbEchantillons(0)
, origine(0)
, vitesse(0)
, mesuresBrutes(nullptr)
{
  LireFichierIni();
}

void Experience::LireFichierIni()
{
  QString nomFichierIni = "../Equilibreuse_TDs_Fichiers_Etudiants/files/equilibreuse.ini";
  QFileInfo fichierIni(nomFichierIni);
  QSettings paramsEquilibreuse(nomFichierIni,QSettings::IniFormat);
  if (fichierIni.exists() && fichierIni.isFile())
    {
      // à compléter la lecture du fichier

      paliers[PALIER_A].jauge.capacite = paramsEquilibreuse.value("JaugeA/capacite").toDouble();
      paliers[PALIER_A].jauge.date = paramsEquilibreuse.value("JaugeA/date").toString();
      paliers[PALIER_A].jauge.modele = paramsEquilibreuse.value("JaugeA/modele").toString();
      paliers[PALIER_A].jauge.sensibilite = paramsEquilibreuse.value("JaugeA/sensibilite").toDouble();
      paliers[PALIER_A].jauge.numeroDeSerie = paramsEquilibreuse.value("JaugeA/serie").toString();

      paliers[PALIER_O].jauge.capacite = paramsEquilibreuse.value("Jauge0/capacite").toDouble();
      paliers[PALIER_O].jauge.date = paramsEquilibreuse.value("Jauge0/date").toString();
      paliers[PALIER_O].jauge.modele = paramsEquilibreuse.value("Jauge0/modele").toString();
      paliers[PALIER_O].jauge.sensibilite = paramsEquilibreuse.value("Jauge0/sensibilite").toDouble();
      paliers[PALIER_O].jauge.numeroDeSerie = paramsEquilibreuse.value("Jauge0/serie").toString();
    }
  else
    {
      // si le fichier n’existe pas, il est créé avec les valeurs par défaut
      paliers[PALIER_A].jauge.capacite = 25;
      paliers[PALIER_A].jauge.date = "09-22-1998";
      paliers[PALIER_A].jauge.modele = "MB-25";
      paliers[PALIER_A].jauge.sensibilite = 3.348;
      paliers[PALIER_A].jauge.numeroDeSerie = "C30629";

      paliers[PALIER_O].jauge.capacite = 25;
      paliers[PALIER_O].jauge.date = "10-52-1998";
      paliers[PALIER_O].jauge.modele = "MB-25";
      paliers[PALIER_O].jauge.sensibilite = 3.328;
      paliers[PALIER_O].jauge.numeroDeSerie = "C30637";
      // il est ensuite enregistré
      EnregistreFichierIni(paliers);
    }
}

void Experience::EnregistreFichierIni(const typePalier _paliers[])
{
  QString nomFichierIni = "../Equilibreuse_TDs_Fichiers_Etudiants/files/equilibreuse.ini";
  QFileInfo fichierIni(nomFichierIni);
  QSettings paramsEquilibreuse(nomFichierIni,QSettings::IniFormat);

  paramsEquilibreuse.beginGroup("Jauge_A");
  paramsEquilibreuse.setValue("capacite",_paliers[PALIER_A].jauge.capacite);
  paramsEquilibreuse.setValue("date",_paliers[PALIER_A].jauge.date);
  paramsEquilibreuse.setValue("modele",_paliers[PALIER_A].jauge.modele);
  paramsEquilibreuse.setValue("sensibilite",_paliers[PALIER_A].jauge.sensibilite);
  paramsEquilibreuse.setValue("serie",_paliers[PALIER_A].jauge.numeroDeSerie);
  paramsEquilibreuse.endGroup();

  paramsEquilibreuse.beginGroup("Jauge_O");
  paramsEquilibreuse.setValue("capacite",_paliers[PALIER_O].jauge.capacite);
  paramsEquilibreuse.setValue("date",_paliers[PALIER_O].jauge.date);
  paramsEquilibreuse.setValue("modele",_paliers[PALIER_O].jauge.modele);
  paramsEquilibreuse.setValue("sensibilite",_paliers[PALIER_O].jauge.sensibilite);
  paramsEquilibreuse.setValue("serie",_paliers[PALIER_O].jauge.numeroDeSerie);
  paramsEquilibreuse.endGroup();
}

typePalier *Experience::ObtenirCarateristiquesPaliers()
{
  return paliers;
}

void Experience::LireMesuresBrutes(QString &_nomFichier)
{
  // à completer dans le TD2
  mesuresBrutes = new double[NB_ECHANTILLONS_PAR_CANAL * 2];
  QFile file(_nomFichier);
  if(!file.open(QIODevice::ReadOnly))
    {
      qDebug() << file.errorString();
    }
  else
    {
      QDataStream in(&file);
      in >> nbEchantillons >> vitesse >> origine;
      for(quint16 i = 0; i < nbEchantillons; i++)
        {
          in >> mesuresBrutes[i];
        }
      file.close();
    }
}

void Experience::InitiliserCourbes()
{
  int indiceFin = nbEchantillons / 2 ;
  int indiceA = 0;
  int indiceO = nbEchantillons / 2 ;

  courbeA.clear();
  courbeO.clear();
  PointDeCourbe unPoint;
  for(int i = 0 ; i < indiceFin ; i++)
    {
      unPoint.setX(i);
      unPoint.setY(mesuresBrutes[indiceA++]);
      courbeA.append(unPoint);
      unPoint.setY(mesuresBrutes[indiceO++]);
      courbeO.append(unPoint);
    }
}

QList<QPointF> *Experience::ObtenirCourbeA()
{
  return (QList<QPointF>*) &courbeA;
}

QList<QPointF> *Experience::ObtenirCourbeO()
{
  return (QList<QPointF>*) &courbeO;
}

void Experience::ObtenirTypeAffichage(bool &_newton, bool &_pointCodeur)
{
  _newton = false;
  _pointCodeur = true;
}

/**
 * @brief Experience::RechercherEffortMax
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return Le point possedant la valeur de l'effort le plus grand
 * @details Recherche le point dont l'amplitude est la plus grande sur l'une des 2 courbes.
 */
QPointF Experience::RechercherEffortMax(QChar courbe)
{
  QList<PointDeCourbe> *laCourbe = &courbeO;
  if(courbe =='A')
    laCourbe = &courbeA;

  QList<PointDeCourbe>::iterator max = std::max_element(laCourbe->begin(), laCourbe->end());
  return *max;
}

/**
 * @brief Experience::RechercherEffortAzero
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort pour à l'origine de la courbe
 */
double Experience::RechercherEffortAzero(QChar courbe)
{
  QList<PointDeCourbe> *laCourbe = &courbeO;
  if(courbe =='A')
    laCourbe = &courbeA;
  return laCourbe->at(0).y();
}

/**
 * @brief Experience::RechercherEffortAquatreVingtDix
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort à 90°
 */
double Experience::RechercherEffortAquatreVingtDix(QChar courbe)
{
  QList<PointDeCourbe> *laCourbe = &courbeO;
  if(courbe =='A')
    laCourbe = &courbeA;
  return laCourbe->at(250).y();   // 90° * 1000 ptsCodeur / 360°
}

/**
 * @brief Experience::ObtenirVitesse
 * @return La vitesse de l'expérience courante
 */
qint16 Experience::ObtenirVitesse()
{
  return vitesse;
}
