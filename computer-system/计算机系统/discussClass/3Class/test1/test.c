#include <stdio.h>

int main()

{
  float a[3] = {1143139122437582505939828736.0, 76482007234779498639230238720.0,
                9.222452464e-39};
  char *b = "Hello world";

  printf("%d ", sizeof(float));

  printf("%s ", a);

  return 0;
}