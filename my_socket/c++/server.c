#include "head.hpp"
#define MAXLINE 4096

int main(int argc, char* argv[]) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  //   struct sockaddr_in {
  // 	__uint8_t       sin_len;      //
  // 	sa_family_t     sin_family;   //定义是哪种地址族
  // 	in_port_t       sin_port;     //保存端口号
  // 	struct  in_addr sin_addr;     //保存IP地址信息
  // 	char            sin_zero[8];  //没有特殊含义
  // };
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

  if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) ==
      -1) {  // file descriptor,返回了文件描述符(connect file descriptor)
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