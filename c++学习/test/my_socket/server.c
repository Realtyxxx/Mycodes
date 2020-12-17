// #include <arpa/inet.h>   //提供IP地址转换函数,inet_pton()
// #include <errno.h>       //提供错误号errno的定义，用于错误处理
// #include <netinet/in.h>  //定义数据结构sockaddr_in
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>  //提供socket函数及数据结构
// #include <sys/types.h>   //数据类型定义
// #include <unistd.h>  //提供通用的文件、目录、程序及进程操作的函数,close()
#include "head.hpp"
#define MAXLINE 4096

int main(int argc, char* argv[]) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buff[MAXLINE];
  int n;
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) ==
      -1) {  // Af_INET 指定IPv4，SOCK_STREAM指定TCP
    printf("create socket error: %s(errno : %d)\n", strerror(errno), errno);
    exit(0);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;                 // match the socket() call
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // bind to local  address,
  // – htons(), htonl(): host to network short/long
  //– ntohs(), ntohl(): network order to host short /long

  servaddr.sin_port = htons(8080);  // specify the port
  if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
    printf("bind socket error: %s(errno : %d)\n", strerror(errno), errno);
    exit(0);
  }
  if (listen(listenfd, 10) == -1) {
    printf("listen socket error: %s(errno : %d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("========waiting for client's request========\n");

  if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1) {    //file descriptor,返回了文件描述符 
    printf("accept socket error: %s\n", strerror(errno), errno);
    exit(0);
  }
  while (1) {
    n = recv(connfd, buff, MAXLINE, 0);
    buff[n] = '\0';
    printf("recv msg from client: %s\n", buff);
  }
  close(connfd);

  close(listenfd);
}