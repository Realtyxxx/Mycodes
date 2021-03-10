#include <stdio.h>

int main() {
  char a[] = {'H', 'N', 'U', 'e', 'r', '\0'};
  char b[6] = {72, 78, 85, 101, 114, 0};

  printf("%d\n", sizeof(char));
  printf("%s\n", a);
  printf("%s\n", b);

  return 0;
}