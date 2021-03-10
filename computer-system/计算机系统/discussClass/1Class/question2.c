#include <stdio.h>

int main() {
	char a[6]={'H','N','U','e','r','\0'};
	char b[6]={72,78,85,101,114,0};
	int c[2]={(72<<24)+(78<<16)+(85<<8)+101,114<<24};

	printf("%d,%d\n",sizeof(char),sizeof(int));
	printf("%s\n",a);
	printf("%s\n",b);

	printf("%d,%d\n",c[0],c[1]);
	// char * d = (char*)c;
	// d[4] = 114;
	// d[5] = 114;
	// d[6] = 114;
	printf("%s\n",c);
	char* d = (char *)c;
	for (int i = 0 ;i < 8; ++i) {
		printf("%c ",d[i]);
	}
	return 0;
}

//gdb x /nfu <addr>
// x 是 examine 的缩写

// n表示要显示的内存单元的个数

// f表示显示方式, 可取如下值
// x 按十六进制格式显示变量。
// d 按十进制格式显示变量。
// u 按十进制格式显示无符号整型。
// o 按八进制格式显示变量。
// t 按二进制格式显示变量。
// a 按十六进制格式显示变量。
// i 指令地址格式
// c 按字符格式显示变量。
// f 按浮点数格式显示变量。

// u表示一个地址单元的长度
// b表示单字节，
// h表示双字节，
// w表示四字节，
// g表示八字节


// ————————————————
// 版权声明：本文为CSDN博主「公众号：程序芯世界」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/baidu_24256693/article/details/47298513

/* 
1,4
HNUer
HNUer
*/