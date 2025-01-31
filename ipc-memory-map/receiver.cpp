#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("mmap_file", O_RDONLY);
    char *ptr = (char *)mmap(NULL, 100, PROT_READ, MAP_SHARED, fd, 0); // Explicit cast
    printf("Reader read: %s\n", ptr);
    munmap(ptr, 100);
    close(fd);
    return 0;
}