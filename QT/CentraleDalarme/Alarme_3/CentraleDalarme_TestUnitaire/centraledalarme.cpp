#include "centraledalarme.h"
#include "clavier.h"

CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *_parent) :
  QObject(_parent),
  tailleCode(_tailleCode),
  indiceCourant(0)
{
  combinaison = new quint8[tailleCode];
  for(int i = 0 ; i < tailleCode ; i++)
    combinaison[i]=0;

  leClavier = new Clavier(this);
  leClavier->show();
}

CentraleDalarme::~CentraleDalarme()
{
  delete[] combinaison;
  delete leClavier;
}

void CentraleDalarme::FabriquerCode(const quint8 _chiffre)
{
  int indice;
  if (indiceCourant == tailleCode)
    {
      for(indice = 0; indice < tailleCode -1; indice++)
        {
          combinaison[indice] = combinaison[indice+1];
        }
      combinaison[indice] = _chiffre;
    }
  else
    {
      combinaison[indiceCourant] = _chiffre;
      indiceCourant ++;
    }

  // Affichage de la combinaison lors de sa construction
  QString tampon = "Combinaison = ";
  for(int i = 0 ; i < tailleCode; i++)
    tampon += QString::number(combinaison[i]);
  qDebug() << tampon;

}
