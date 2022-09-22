#include "guitare.h"

int main()
{
    InstrumentDeMusique unInstrument("Piano");
    unInstrument.Afficher() ;
    InstrumentACordes unInstrumentACordes("Basse", 4);
    unInstrumentACordes.Afficher();
    Guitare uneGuitare("Guitare", 6, "Fender");
    uneGuitare.Afficher();
    return 0;
}
