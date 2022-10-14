#include "stock.h"

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
  insert(_nouveau);
}

int Stock::RechercherSerie(POSITION_STOCK &_positionDebut)
{
  POSITION_STOCK itDebut = begin();
  POSITION_STOCK itFin = begin();
  POSITION_STOCK positionRetenue = begin();
  int retour = size();
  if (retour >=3)
    {
      retour = 3;
      for(int i = 0; i < 3; i++)
        {
          itFin++;
        }
      int difference = *itFin - *itDebut;
      while (itFin != end())
        {
          itDebut++;
          itFin++;
          int difference2 = *itFin - *itDebut;
          if (difference2 < difference)
            {
              positionRetenue = itDebut;
              difference = difference2;
            }
        }
      _positionDebut = itDebut;
    }
  else
    {
      _positionDebut = itDebut;
    }
  return retour;
}

void Stock::SortirRouleau(const POSITION_STOCK _positionRouleau)
{
  erase(_positionRouleau);
}

void Stock::Visualiser() const
{
  POSITION_STOCK it;
  for (it = begin(); it != end(); it++)
    {
      it->Visualiser();
    }
}
