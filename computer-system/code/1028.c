#include <stdio.h>
#include <stdlib.h>
int main()
{
	//----指针变量的定义
	int i;	//定义一个整数
	i=10;
	int j=0;
	j=++i+(++i);
//	int * pi;	//定义一个变量pi 给pi分配4个字节，用于存放地址
//	pi=&i;
//	*pi=11;
//	int *pi2;
//	pi2=&i;
//	*pi2=12;
	float* pf;	//定义了一个变量pf
//	pf= malloc(4);   //内存泄漏
//	*pf=15213.0f;
	pf=&i;
//	*pf=15213.0f;
//	*pf=(int)15213;
//	*pi=(int)15213;
//	pf=pf+1;
//	short* ps;
//	ps=&i;
//	ps=ps+1;
//	char *ph;
//	ph=&i;
//	ph=ph+1;
//	ps=ph;
//	*ps=0x0102;
//	int iarr[3];
//	float * piarr[3];
//	int ** pi;
//	piarr[0]=&i;
//	piarr[1]=piarr[0]+1;
//	piarr[2]=iarr;
	


	return 0;
}
