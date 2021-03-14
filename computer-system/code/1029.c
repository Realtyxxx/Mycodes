#include <stdio.h>

int main()
{
	int i=0x7fffffff;
	float f=(float)i;
	int k=(int)f;
	printf("%d,%f,%d\n",i,f,k);
	return 0;
}
