#include <stdio.h>
int max(int a, int b){
	return a >= b? a: b;
}

int main() {
  int a = 1;
  int b = 2;
  int sum = a + b;
  int sub = b - a;
  int mul = a * b;
	int div = a / b;
	if ( sum > 0) {
		printf("%d\n",max(a, b));
	}
}