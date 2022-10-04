#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void traitement(int sig)
{
    (void) signal(SIGUSR1, traitement);
    printf("signal SIGUSR1 dans le process ayant pour pid : %d\n", getpid());
}

int main(int argc, char** argv)
{
    int pid, pidP1, pidP2, pidP3;
    int tube[2];
    int nbOctets;
    (void) signal(SIGUSR1, traitement);
    // P1
    pidP1 = getpid();
    if (pipe(tube) == 0)
    {
        pid = fork();
        if (pid == 0) // P2
        {
            pidP2 = getpid();
            pid = fork();
            if (pid == 0) // P3
            {
                pidP3 = getpid();
                printf("je suis P3, pid : %d\n", pidP3);
                // ecrire pid dans le tube
                nbOctets = write(tube[1], &pidP3, sizeof (pidP3));
                // attente signal
                pause();
            }
            else // P2
            {
                printf("je suis P2, pid : %d\n", getpid());
                pidP3 = pid;
                // attente signal
                pause();
            }
        }
        else // P1
        {
            pidP2 = pid;
            printf("je suis P1, pid : %d\n", pidP1);
            sleep(2);
            // envoyer signal à P2
            kill(pidP2, SIGUSR1);
            // récupérer pidP3 via le tube
            nbOctets = read(tube[0], &pidP3, sizeof (pidP3));
            printf("je suis P1 (%d), pidP3 : %d\n", getpid(), pidP3);
            kill(pidP3, SIGUSR1);
        }
    }
    return (EXIT_SUCCESS);
}

