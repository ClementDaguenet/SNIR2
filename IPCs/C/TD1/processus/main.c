#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //    int pid1, pid2, pid3;
    //    pid1 = fork();
    //    if (pid1 == 0) //p3
    //    {
    //        pid2 = fork();
    //        if (pid2 == 0) //p2
    //        {
    //            pid3 = fork();
    //            if (pid3 == 0) //p1
    //            {
    //                printf("p1\n");
    //            }
    //            else //p2
    //            {
    //                printf("p2\n");
    //            }
    //        }
    //        else //p3
    //        {
    //            printf("p3\n");
    //        }
    //    }
    //    else //p4
    //    {
    //        printf("p4\n");
    //    }
    for (int i = 0; i < 6; i++)
    {
        system("firefox");
        usleep(5000);
    }
    return EXIT_SUCCESS;
}

