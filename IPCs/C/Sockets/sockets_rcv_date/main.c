#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

struct dateRecue
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
    // initialiser la structure sockaddr_in avec l'adresse et le port du serveur (172.18.18.158 2222)
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosReception;
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(4444); // de l'hote vers le réseau sur 2 octets
    infosServeur.sin_addr.s_addr = INADDR_ANY;
    struct dateRecue date;
    // associer ip et port pour le serveur
    int retour = bind(sock, (struct sockaddr *) &infosServeur, sizeof (infosServeur));
    if (retour == -1)
    {
        printf("PB retour bind : %s\n", strerror(errno));
        exit(errno);
    }
    do
    {
        // recevoir un entier de la part du client
        socklen_t taille = sizeof (infosReception);
        retour = recvfrom(
                          sock,
                          &date,
                          sizeof (date),
                          0,
                          (struct sockaddr *) &infosReception,
                          &taille);
        if (retour == -1)
        {
            printf("PB retour recvfrom : %s\n", strerror(errno));
            exit(errno);
        }
        // afficher la date reçue
        printf("| Date : %s %.2d/%.2d/%.4d | Adresse : %s |\n", date.jourDeLaSemaine, date.jour, date.mois, date.annee, inet_ntoa(infosReception.sin_addr));
    }
    while (1 == 1);
    return (EXIT_SUCCESS);
}
