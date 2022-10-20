#include "../../Struct/memoire.h"

// P2 met continuellement à jour le champ ordre.

char randomChar()
{
    return (rand() % 26 + 'A');
}

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
        printf("P2 initialise char\n");
        ZoneDePartage->ordre = randomChar();
        sleep(1);
    }
    while (1);
    return (0);
}
