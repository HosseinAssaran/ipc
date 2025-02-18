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
    // Open message queue
    mqd_t mq = mq_open(MQ_NAME, O_CREAT | O_RDONLY, 0666, NULL);
    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        exit(1);
    }

    // Buffer for receiving message
    char message[MAX_SIZE];

    // Receive message
    if (mq_receive(mq, message, MAX_SIZE, NULL) == -1)
    {
        perror("mq_receive");
        exit(1);
    }

    printf("Receiver received: %s\n", message);

    // Close and unlink the message queue
    mq_close(mq);
    mq_unlink(MQ_NAME);

    return 0;
}
