#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex;


int main(int argc, char *argv[]) {
 sem_init(&mutex, 1, 1);
 int rc1 = fork();
 int rc2 = fork();
 sem_wait(&mutex);
 for (int i=0; i<2; i++){
    printf("Hello from (pid = %d)\n", (int)getpid());
 }
 sem_post(&mutex);
 return 0;
}
