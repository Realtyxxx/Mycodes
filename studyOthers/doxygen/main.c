#include "dev.h"

#define CNT_MAX 10

void DEV_Example(void)
{
	int i = 0;

	Dev_Init();
	
	for (i = 0; i < CNT_MAX; ++i)
	{
		Dev_PrintInt(i);
	}

	Dev_Close();
}

int main(void)
{

	DEV_Example();

	return 0;
}