#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("shm_file", 65);
    int shmid = shmget(key, 1024, 0666);
    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Reader read: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL); // Destroy the shared memory
    return 0;
}