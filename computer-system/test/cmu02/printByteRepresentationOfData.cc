#include <stdio.h>

#include <iostream>
typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf("%p\t0x%.2x\n", start + i, start[i]);
  }
  printf("\n");
}

int main() {
  int a = 15213;
  std::cout << "int a = 15213" << std::endl;
	show_bytes((pointer)&a,sizeof(int));
	return 0;
}

// %p print pointers
// %x print Hexadecimal