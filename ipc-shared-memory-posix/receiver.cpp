#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/posix_shm"
#define SHM_SIZE 1024

int main()
{
    // Open shared memory object
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    // Map shared memory into process address space
    char *shm_ptr = (char *)mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    // Read from shared memory
    printf("Reader read: %s\n", shm_ptr);

    // Unmap and close shared memory
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);

    // Remove the shared memory object
    shm_unlink(SHM_NAME);

    return 0;
}
