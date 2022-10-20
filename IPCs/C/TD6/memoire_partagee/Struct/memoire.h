#ifndef MEMOIRE_H
#define MEMOIRE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

struct donnees
{
    float tempe; // Température Update par P1
    int press; // Pression Update par P1
    char ordre; // Ordre Update par P2
};

#ifdef __cplusplus
}
#endif

#endif /* MEMOIRE_H */

