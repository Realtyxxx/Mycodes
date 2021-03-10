#include <stdio.h>

int main() {
  int a, b;
  int max = 0;
  scanf("%d,%d", &a, &b);
  max = a;
  if (b > a) max = b;
	printf("%d", max);
  return 0;
}