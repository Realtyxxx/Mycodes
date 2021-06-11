#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "unixerr.h"


void sigint_handler(int sig) {
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(2);
  printf("Well\n");
  fflush(stdout);
  sleep(1);
  printf("OK! motherfucker ,you got me\n");
  exit(0);
}

int main() {
  /* Install the SIGINT handler */
  if (signal(SIGINT, sigint_handler) == SIG_ERR) unix_error("signal error");
  pause();
  return 0;
}