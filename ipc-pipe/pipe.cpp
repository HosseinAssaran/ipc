#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Pipe
{
public:
    int fd[2]; // File descriptors for pipe
    Pipe()
    {
        if (pipe(fd) == -1)
        {
            perror("pipe failed");
            exit(EXIT_FAILURE);
        }
    }
    ~Pipe()
    {
        close(fd[0]);
        close(fd[1]);
    }
    int read_fd() const { return fd[0]; }
    int write_fd() const { return fd[1]; }
};

void process(Pipe &pipe)
{
    int value;
    while (true)
    {
        read(pipe.read_fd(), &value, sizeof(value));
        std::cout << "Process received: " << value << std::endl;
        if (value >= 10)
            break;
        ++value;
        write(pipe.write_fd(), &value, sizeof(value));
    }
}

int main()
{
    Pipe pipe;

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    { // Child process
        process(pipe);
    }
    else
    { // Parent process
        int value = 1;
        write(pipe.write_fd(), &value, sizeof(value));

        process(pipe);
        wait(nullptr); // Wait for child process to finish
    }

    return 0;
}
