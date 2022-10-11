#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

char message[255]; // Zone commune

void *traitement(void *arg)
{
    printf("PID thread : %d\n", getpid());
    printf("Tid thread : %d\n", syscall(SYS_gettid));
    printf("Dans le thread l'argument était :%s\n", (char *) arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit((void *) "Merci pour le temps CPU");
}

int main()
{
    int res;
    pthread_t un_thread;
    void *thread_result;
    strcpy(message, " Debian inside");
    printf("PID process thread : %d\n", getpid());
    printf("Tid process thread : %d\n", syscall(SYS_gettid));
    res = pthread_create(&un_thread, NULL, traitement, (void *) message);
    if (res != 0)
    {
        perror("Thread creation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Attente de la fin du thread...\n");
    res = pthread_join(un_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join a échoué\n");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join : %s\n", (char *) thread_result);
    printf("Le message est maintenant : %s\n", message);
    exit(EXIT_SUCCESS);
}
