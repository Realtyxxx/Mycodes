#include <pthread.h>
// #include <sys/types.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
  pid_t pid = fork();
  if (pid == 0) {
    cout << "call from child";
  } else {
    cout << "call from parents";
  }
  return 0;
}