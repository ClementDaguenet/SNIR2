#include "zonearrosage.h"


ZoneArrosage::ZoneArrosage(int _numZone, const int _commandeVanne, const int _senseAVanne, const int _senseBVanne, const int _brocheHumidite):
    laVanne(nullptr),
    leCapteurHumidite(nullptr),
    numZone(_numZone)
{
    laVanne = new Vanne(_commandeVanne,_senseAVanne,_senseBVanne);
    leCapteurHumidite = new CapteurHumidite(_brocheHumidite);
    cout << "Constructeur ZoneArrosage" << endl;
}

ZoneArrosage::ZoneArrosage(const string _initialisationZone)
{
    int parametres[5];
    size_t prec = 0;
    size_t pos = 0;
    for (int indice = 0; indice < 4; indice++)
    {
        pos = _initialisationZone.find(' ',prec);
        parametres[indice] = atoi(_initialisationZone.substr(prec,pos).c_str());
        prec = pos + 1; // on incrémente pos pour le tour d'après.
    }
    numZone = parametres[0];
    laVanne = new Vanne(parametres[1],parametres[2],parametres[3]);
    leCapteurHumidite = new CapteurHumidite(parametres[4]);
}

ZoneArrosage::~ZoneArrosage()
{
    if (laVanne != nullptr)
        delete laVanne;
    if (leCapteurHumidite != nullptr)
        delete leCapteurHumidite;
}

void ZoneArrosage::Piloter()
{

}
