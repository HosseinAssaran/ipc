#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

#define MQ_NAME "/posix_mq"
#define MAX_SIZE 100

int main()
{
    struct mq_attr attr;
    attr.mq_flags = 0;          // Blocking mode
    attr.mq_maxmsg = 10;        // Max messages in the queue
    attr.mq_msgsize = MAX_SIZE; // Max size per message
    attr.mq_curmsgs = 0;
    
    // Open message queue
    mqd_t mq = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0666, &attr);
    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        exit(1);
    }

    // Message to send
    char message[MAX_SIZE] = "Hello from sender!";

    // Send message
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1)
    {
        perror("mq_send");
        exit(1);
    }

    printf("Sender sent: %s\n", message);

    // Close message queue
    mq_close(mq);

    return 0;
}
