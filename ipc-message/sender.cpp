#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
} message;

int main()
{
    key_t key = ftok("msg_queue", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    sprintf(message.msg_text, "Hello from sender!");
    msgsnd(msgid, &message, sizeof(message), 0);
    return 0;
}