#include <stdio.h>
int main() {
  int i = __INT32_MAX__;

  float f = i;

  int j = (int)f;
  printf("%d, %f, %d", i, f, j);

  if (i == j) {
    printf("equal!!\n");
  }
  return 0;
}