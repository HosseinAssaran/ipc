#include "shm_sem.h"

int main()
{
    // Create or open the shared memory object
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open failed");
        return 1;
    }

    // Set the size of the shared memory
    ftruncate(shm_fd, SHM_SIZE);

    // Map the shared memory into the process's address space
    shared_data *shm_ptr = (shared_data *)mmap(NULL, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED)
    {
        perror("mmap failed");
        return 1;
    }

    // Create or open the semaphore
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 0);
    if (sem == SEM_FAILED)
    {
        perror("sem_open failed");
        return 1;
    }

    // Write a message to shared memory
    const char *msg = "Hello from Process A (Writer)!";
    strncpy(shm_ptr->message, msg, SHM_SIZE);
    printf("Process A: Wrote message to shared memory: %s\n", shm_ptr->message);

    // Signal Process B that the message is ready
    printf("Process A: Signaling Process B...\n");
    sem_post(sem);

    // Clean up
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);

    return 0;
}