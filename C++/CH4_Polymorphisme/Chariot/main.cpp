#include "segment.h"
#include "pause.h"
#include "arc.h"
#include "trajectoire.h"

int main()
{
    Trajectoire laTrajectoire(5);

    laTrajectoire.Ajouter(new Segment(3,9,0));
    laTrajectoire.Ajouter(new Segment(1,5,0.927295));
    laTrajectoire.Ajouter(new Segment(2,6,1.5708));
    laTrajectoire.Ajouter(new Pause(4));
    laTrajectoire.Ajouter(new Arc(6,5,M_PI,0));

    laTrajectoire.Afficher();
    cout << endl;
    return 0;
}
