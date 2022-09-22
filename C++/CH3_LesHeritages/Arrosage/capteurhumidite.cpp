#include "capteurhumidite.h"


CapteurHumidite::CapteurHumidite(const int _brocheCapteur):
    brocheCapteur(_brocheCapteur)
{
    cout << "Constructeur CapteurHumidite" << endl;
}

int CapteurHumidite::MesurerHumiditeDuSol()
{
    return 0;
}
