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

int main() {
  pid_t pid[N];
  int i, child_status;
  signal(SIGINT, int_handler);
  for (int i = 0; i < N; i++) {
    if ((pid[i] = fork()) == 0) {
      while (1)
        ;
    }
  }
}