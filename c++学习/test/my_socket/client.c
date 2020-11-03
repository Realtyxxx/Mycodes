#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXLINE 4096

int main(int argc, char** argv) {
  int sockfd, n;
  char recvline[4096], sendline[MAXLINE];
  struct sockaddr_in servaddr;
  if (argc != 2) {
    printf("Usage: ./client <ipaddress>\n") exit(0);
  }
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("create socket error: %s(errno : %d)\n", strerror(errno), errno);
    exit(0);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6666);
  if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0){
      printf("inet_pton error for %s(errno: %d)\n",strerror(errno),errno);
      exit(0);
  }


}