#ifndef SHM_SEM_H
#define SHM_SEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"       // Name for shared memory
#define SEM_NAME "/my_semaphore" // Name for semaphore
#define SHM_SIZE 1024            // Size of shared memory

// Structure for shared data
typedef struct
{
    char message[SHM_SIZE]; // Message buffer
} shared_data;

#endif