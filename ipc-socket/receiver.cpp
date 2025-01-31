#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
    int server_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "socket_file");
    bind(server_socket, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_socket, 5);
    int client_socket = accept(server_socket, NULL, NULL);
    char buffer[100];
    read(client_socket, buffer, sizeof(buffer));
    printf("Server received: %s\n", buffer);
    close(client_socket);
    close(server_socket);
    unlink("socket_file");
    return 0;
}