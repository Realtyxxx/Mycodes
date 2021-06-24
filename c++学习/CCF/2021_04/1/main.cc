#include <stdio.h>
int main() {
  int n, m, L, temp;
  int i = 0;
  int h[257] ={0};
  
  scanf("%d %d %d", &n, &m, &L);
  for (int i = 0; i < n * m; i++) {
    scanf("%d", &temp);
    h[temp]++;
  }
  for (; i < L; i++) printf("%d ", h[i]);
  return 0;
}