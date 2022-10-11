#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

struct datePerso
{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[10];
};

int main(int argc, char** argv)
{
    // créer une socket DGRAM(udp)
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1)
    {
        printf("PB socket : %s\n", strerror(errno));
        exit(errno);
    }
    struct sockaddr_in infosServeur;
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(4444);
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.146");
    struct datePerso date;
    strcpy(date.jourDeLaSemaine, "Mardi");
    date.jour = 11;
    date.mois = 10;
    date.annee = 2022;
    int retour = sendto(sock, &date, sizeof (date), 0, (struct sockaddr *) &infosServeur, sizeof (infosServeur));
    return (EXIT_SUCCESS);
}
