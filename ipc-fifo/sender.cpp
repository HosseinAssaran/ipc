#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("my_fifo", O_WRONLY);
    write(fd, "Hello from writer!", 19);
    close(fd);
    return 0;
}