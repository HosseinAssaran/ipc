#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/posix_shm"
#define SHM_SIZE 1024

int main()
{
    // Create shared memory object
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    // Set the size of the shared memory
    ftruncate(shm_fd, SHM_SIZE);

    // Map shared memory into process address space
    char *shm_ptr = (char *)mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    // Write data to shared memory
    sprintf(shm_ptr, "Hello from writer!");
    printf("Writer wrote: %s\n", shm_ptr);

    // Unmap and close shared memory
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);

    return 0;
}
