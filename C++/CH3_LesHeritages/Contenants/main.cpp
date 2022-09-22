#include "carton.h"
#include "caissedebouteilles.h"

int main()
{
    Carton leCarton(50,40,30,500);
    CaisseDeBouteilles uneCaisse(50,40,30,6,33);

    cout << endl << "Volume de la caisse : " << uneCaisse.CalculerVolume() << " cl" << endl;
    Contenant *ptrContenant = static_cast<Contenant *>(&uneCaisse);
    cout << "Volume brut de la caisse " << ptrContenant->CalculerVolume() << " cm3" << endl;
    cout << "Volume de " << uneCaisse.Contenant::CalculerVolume()/100 << " m3" << endl;

    cout << endl;

    return 0;
}
