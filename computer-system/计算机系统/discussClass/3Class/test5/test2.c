#include <stdio.h>
int main() {
  double d1 = 0.6;
  float f = (float)d1;
  double d2 = f;
  
  printf("%lf,%lf \n", d1, d2);
  return 0;
}