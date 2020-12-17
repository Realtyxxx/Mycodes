//通用网络编程函数

#include <arpa/inet.h>  //提供IP地址转换函数,inet_pton()
#include <ctype.h>
#include <errno.h>  //提供错误号errno的定义，用于错误处理
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>  //定义数据结构sockaddr_in
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>  //提供socket函数及数据结构
#include <sys/types.h>   //数据类型定义
#include <unistd.h>  //提供通用的文件、目录、程序及进程操作的函数,close()
                     // #include <malloc.h> //内含在stdlib.h