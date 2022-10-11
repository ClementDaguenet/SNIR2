#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int valRec;
    // créer une socket DGRAM(udp)
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1)
    {
        printf("PB socket : %s\n", strerror(errno));
        exit(errno);
    }
    // initialiser la structure sockaddr_in avec l'adresse et le port du serveur (172.18.18.158 2222)
    struct sockaddr_in infosServeur;
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(2222); // de l'hote vers le réseau sur 2 octets
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.114");
    // envoyer un entier au serveur
    int valEnv = 5;
    int retour = sendto(sock, &valEnv, sizeof (valEnv), 0, (struct sockaddr *) &infosServeur, sizeof (infosServeur));
    if (retour == -1)
    {
        printf("PB retour : %s\n", strerror(errno));
        exit(errno);
    }
    // recevoir un entier de la part du serveur
    socklen_t fromlen = sizeof (infosServeur);
    retour = recvfrom(sock, &valRec, sizeof (valRec), 0, (struct sockaddr *) &infosServeur, &fromlen);
    if (retour == -1)
    {
        printf("PB retour : %s\n", strerror(errno));
        exit(errno);
    }
    // afficher l'entier reçu
    usleep(50000);
    printf("Valeur reçue : %d\n", valRec);
    return (EXIT_SUCCESS);
}
