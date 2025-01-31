#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
    int client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "socket_file");
    connect(client_socket, (struct sockaddr *)&addr, sizeof(addr));
    write(client_socket, "Hello from client!", 19);
    close(client_socket);
    return 0;
}