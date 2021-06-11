#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 12

void int_handler(int sig) {
  printf("Process %d received signal %d \n", getpid(), sig);
  exit(0);
}

void fork12() {
  pid_t pid[N];
  int i;
  int child_status;
  for (i = 0; i < N; i++) {
    /* Child: Infinite Loop */
    if ((pid[i] = fork()) == 0)
      while (1)
        // sleep(2);
        ;
  }
  for (i = 0; i < N; i++) {
    printf("Killing processing %d\n", i);
    kill(pid[i], SIGINT);
  }
  for (i = 0; i < N; i++) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status))
      printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
    else
      printf("Child %d terminated abnormally\n", wpid);
  }
}

void fork13() {
  pid_t pid[N];
  int i;
  int child_status;
  signal(SIGINT, int_handler);
  for (i = 0; i < N; i++) {
    /* Child: Infinite Loop */
    if ((pid[i] = fork()) == 0)
      while (1)
        // sleep(2);
        ;
  }
  for (i = 0; i < N; i++) {
    printf("Killing processing %d\n", i);
    kill(pid[i], SIGINT);
  }
  for (i = 0; i < N; i++) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status))
      printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
    else
      printf("Child %d terminated abnormally\n", wpid);
  }
}
int main() {
  printf("fork 12 ------------------------------------\n");
  fork12();
  printf("fork 1 ------------------------------------\n");
  fork13();
  return 0;
}