#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid;
    int pidFils;
    char buffer[255];
    int status;
    //P1
    pid = fork();
    if (pid == 0) //P2
    {
        sprintf(buffer, "mon pid : %d, celui de mon pere : %d", getpid(), getppid());
        boite("P2", buffer);
    }
    else //P1
    {
        pid = fork();
        if (pid == 0) //P3
        {
            sprintf(buffer, "mon pid : %d, celui de mon pere : %d", getpid(), getppid());
            boite("P3", buffer);
        }
        else //P1
        {
            wait(NULL);
            sprintf(buffer, "mon pid : %d", getpid());
            boite("P1", buffer);
        }
    }
    return EXIT_SUCCESS;
}