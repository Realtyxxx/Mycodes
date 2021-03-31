#include <stdio.h>
int main() {
  int a = 10, b = 0;
  __asm____volatile__(
      "movl %1,%%eax\n\r"
      "movl %%eax,%0"
      : "=r"(b)
      : "r"(a)
      : "%eax");
  printf("Result: %d, %d", a, b);
  return 0;
}
