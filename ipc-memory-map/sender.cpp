#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("mmap_file", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 100);
    char *ptr = (char *)mmap(NULL, 100, PROT_WRITE, MAP_SHARED, fd, 0); // Explicit cast
    sprintf(ptr, "Hello from writer!");
    munmap(ptr, 100);
    close(fd);
    return 0;
}