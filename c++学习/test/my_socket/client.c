#include "head.hpp"

#define MAXLINE 4096

int main(int argc, char** argv) {
  int sockfd, n;
  char recvline[4096], sendline[MAXLINE];
  struct sockaddr_in servaddr;
  //   struct sockaddr_in {
  // 	__uint8_t       sin_len;      //
  // 	sa_family_t     sin_family;   //定义是哪种地址族
  // 	in_port_t       sin_port;     //保存端口号
  // 	struct  in_addr sin_addr;     //保存IP地址信息
  // 	char            sin_zero[8];  //没有特殊含义
  // };
  if (argc != 2) {
    printf("Usage: ./client <ipaddress>\n");
    exit(0);
  }
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {  //创建套接字
    printf("create socket error: %s(errno : %d)\n", strerror(errno), errno);
    exit(0);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;  //指定IP地址版本为IPV4
  servaddr.sin_port = htons(8080);
  // – htons(), htonl(): host to network short/long
  //– ntohs(), ntohl(): network order to host short /long
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    printf("inet_pton error for %s\n", argv[1]);
    exit(0);
  }
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) <
      0) {  //建立连接
    printf("connect error: %s(errno :%d)\n", strerror(errno), errno);
    exit(0);
  }
  printf("send msg to server: \n");
  while (1) {
    fgets(sendline, 4096, stdin);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {  //数据发送
      printf("send msg error : %s(errno: %d)\n", strerror(errno), errno);
      exit(0);
    }
  }
  close(sockfd);  //关闭套接字
  exit(0);
}