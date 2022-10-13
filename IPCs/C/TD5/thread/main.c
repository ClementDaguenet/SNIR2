#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

typedef struct
{
    int v1;
    int v2;
    int v3;
} laStruct;

laStruct global;
pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *p_data)
{
    laStruct val = *((laStruct *) p_data);
    int tid;
    pthread_mutex_lock(&verrou);
    global = val;
    pthread_mutex_unlock(&verrou);
    tid = syscall(SYS_gettid);
    printf("T1 TID = %d v1 = %d\n", tid, global.v1);
    printf("Argument de T1 : %d\n", val.v1);
    sleep(1);
    pthread_exit((void *) "Terminé pour T1 \n");
}

void *thread2(void *p_data)
{
    laStruct val = *((laStruct *) p_data);
    int tid;
    pthread_mutex_lock(&verrou);
    global = val;
    pthread_mutex_unlock(&verrou);
    tid = syscall(SYS_gettid);
    printf("T2 TID = %d v2 = %d\n", tid, global.v2);
    printf("Argument de T2 : %d\n", val.v2);
    sleep(2);
    pthread_exit((void *) "Terminé pour T2 \n");
}

void *thread3(void *p_data)
{
    laStruct val = *((laStruct *) p_data);
    int tid;
    pthread_mutex_lock(&verrou);
    global = val;
    pthread_mutex_unlock(&verrou);
    tid = syscall(SYS_gettid);
    printf("T3 TID = %d v3 = %d\n", tid, global.v3);
    printf("Argument de T3 : %d\n", val.v3);
    sleep(3);
    pthread_exit((void *) "Terminé pour T3 \n");
}

int main()
{
    int i, res;
    pthread_t T[3];
    void *thread_result;
    laStruct a = {11, 12, 13};
    laStruct b = {21, 22, 23};
    laStruct c = {31, 32, 33};
    res = pthread_create(&T[0], NULL, thread1, &a);
    if (res != 0)
    {
        perror("PB Thread creation 1");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&T[1], NULL, thread2, &b);
    if (res != 0)
    {
        perror("PB Thread creation 2");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&T[2], NULL, thread3, &c);
    if (res != 0)
    {
        perror("PB Thread creation 3");
        exit(EXIT_FAILURE);
    }
    printf("Attente de la fin des thread...\n");
    for (i = 0; i < 3; i++)
    {
        res = pthread_join(T[i], &thread_result);
        if (res != 0)
        {
            perror("PB Thread join");
            exit(EXIT_FAILURE);
        }
        printf("Valeur de retour du thread join : %s", thread_result);
    }
    printf("V1 = %d\nV2 = %d\nV3 = %d\n", global.v1, global.v2, global.v3);
    pthread_mutex_destroy(&verrou);
    exit(EXIT_SUCCESS);
}