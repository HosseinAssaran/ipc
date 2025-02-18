#include "shm_sem.h"

int main()
{
    // Open the shared memory object
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open failed");
        return 1;
    }

    // Map the shared memory into the process's address space
    shared_data *shm_ptr = (shared_data *)mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED)
    {
        perror("mmap failed");
        return 1;
    }

    // Open the semaphore
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED)
    {
        perror("sem_open failed");
        return 1;
    }

    // Wait for Process A to signal
    printf("Process B: Waiting for Process A to signal...\n");
    sem_wait(sem);

    // Read the message from shared memory
    printf("Process B: Read message from shared memory: %s\n", shm_ptr->message);

    // Clean up
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem);
    shm_unlink(SHM_NAME); // Remove shared memory object
    sem_unlink(SEM_NAME); // Remove semaphore

    return 0;
}