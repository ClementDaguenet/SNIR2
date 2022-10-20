#include "../../Struct/memoire.h"

// P1 met continuellement à jour les champs tempe et press.

int randomInt()
{
    return ((int) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

float randomFloat()
{
    return ((float) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int main()
{
    struct donnees *ZoneDePartage;
    int id = shmget((key_t) 1234, sizeof (struct donnees), IPC_CREAT | SHM_W | SHM_R);
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
        printf("P1 initialise tempe et press\n");
        ZoneDePartage->tempe = randomInt();
        ZoneDePartage->press = randomFloat();
        sleep(1);
    }
    while (1);
    return (0);
}
