#include <stdio.h>
int main() {
  unsigned a = 0x210a0eed, b = 0x28214ec0;
  __asm__ __volatile__(
      "movl %[value1],%%eax\n\r"
      "movl %[value2],%%edx\n\r"
      "imul %%eax,%%edx\n\r"
      "movl %%edx,%[value2]"
      : [value2] "=r"(b)
      : [value1] "r"(a), "0"(b)
      : "%eax");
  printf("Result: %d, %x, %x", a, b, b);
  return 0;
}
