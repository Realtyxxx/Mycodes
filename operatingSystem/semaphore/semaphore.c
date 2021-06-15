#include <semaphore.h>

// int sem_init(sem_t * sem, int pshared ,unsigned int value);
// int semp_ost(sem_t * sem);
// int sem_wait(sem_t * sem);
// int sem_destroy(sem_t * sem);

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WORK_SIZE 1024

char work_area[WORK_SIZE];

sem_t bin_sem;

void* thread_function(void* arg);

int main(int argc, char** argv) {
  int ret;
  void* thread_result;
  pthread_t a_thread;

  ret = sem_init(&bin_sem, 0, 0);         //信号量初始为0；
  if (ret != 0) {
    perror("sem_init() is failed!\n");
    exit(EXIT_FAILURE);
  }

  ret = pthread_create(&a_thread, NULL, thread_function, NULL);
  if (ret != 0) {
    perror("pthread_create() failed\n");
  }
  printf("Enter \'end \'to finish!\n");
  while (strncmp("end", work_area, 3) != 0) {
    fgets(work_area, WORK_SIZE, stdin);
    sem_post(&bin_sem);               // 信号量+1
  }

  printf("Waiting for thread join\n");
  ret = pthread_join(a_thread, &thread_result);
  if (ret != 0) {
    perror("pthread_join failed!\n");
    exit(EXIT_FAILURE);
  }

  printf("thread_join()\n");
  sem_destroy(&bin_sem);
  exit(EXIT_FAILURE);
}

void* thread_function(void* arg) {
  sem_wait(&bin_sem);                                   //信号量-1
  while (strncmp("end", work_area, 3) != 0) {
    printf("you input %d characters\n", strlen(work_area) - 1);
    sem_wait(&bin_sem);                                  //信号量-1
  }
  pthread_exit(NULL);
}