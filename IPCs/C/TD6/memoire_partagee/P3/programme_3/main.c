#include "../../Struct/memoire.h"

// P3 affiche continuellement les valeurs de tous les champs de la zone de mémoire partagée.

int main()
{
    struct donnees *ZoneDePartage;
    int id = shmget((key_t) 1234, sizeof (struct donnees), IPC_CREAT | 0600);
    if (id == -1)
    {
        printf("PB shmget : %s\n", strerror(errno));
        exit(errno);
    }
    ZoneDePartage = (struct donnees *) shmat(id, NULL, SHM_W);
    if (ZoneDePartage == NULL)
    {
        printf("PB shmat : %s\n", strerror(errno));
        exit(errno);
    }
    do
    {
        printf("Température : %.1f°C | Pression : %d Pa | Ordre : %c\n\n", ZoneDePartage->tempe, ZoneDePartage->press, ZoneDePartage->ordre);
        sleep(1);
    }
    while (1);
    return (0);
}
