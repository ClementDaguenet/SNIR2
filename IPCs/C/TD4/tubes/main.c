// td3 exo 2
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// fonction de traitement du signal SIGUSR1

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    printf("un signal SIGUSR1 je suis pid :%d\n", getpid());
}

int main(int argc, char *argv[]) {
    int pid ;
    char *msg = "PID de P3";
    int pidP3;
    char buffer[255] = {0}; //declaration et init du buffer de reception
    int tube[2];
    int retour;
    int nbOctets;
    int descTube[2];

    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1


    // Tube
    if (pipe(descTube) == 0) {
        //P1
        pid = fork();
        if (pid == 0) {
            //P2
            pid = fork();

            if (pid == 0) {
                //P3


                pidP3 = getpid();
                //ecrire dans le tube
                nbOctets = write(descTube[1], &pidP3, sizeof (pidP3));
                if (nbOctets == -1) {
                    printf("pb write dans le tube %s", strerror(errno));
                    exit(errno);
                }

                printf("p3 pid=%d\n", getpid());
                pause();
                printf("fin de P3\n");


            } else
                //suite de P2
            {
                printf("p2 pid=%d\n", getpid());
                pause();
                sleep(3);
                printf("fin de P2\n");
            }



        } else
            //suite de P1
        {
            printf("p1 pid=%d\n", getpid());
                sleep(1);


            kill(pid, SIGUSR1);

            //lecture dans le tube 
            nbOctets = read(descTube[0], &pid, sizeof (pid));
            if (nbOctets == -1) {
                printf("pb read dans le tube %s", strerror(errno));
                exit(errno);
            }
            printf("j'ai reçu le pid de P3 : %d\n", pid);
            kill(pid, SIGUSR1);
            sleep(4);

            printf("fin de P1\n");
        }

    } else
        //suite du tube
    {
        printf("pb tube : %s", strerror(errno));
        exit(errno);
    }




    return EXIT_SUCCESS;
}