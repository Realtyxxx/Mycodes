#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;
    
    if (argc != 2)
    {
        fputs("usage: ./client message\n", stderr);
        exit(1);
    }
    str = argv[1];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);
    
    // 由于客户端不需要固定的端口号，因此不必调用 bind()，客户端的端口号由内核自动分配。
    // 注意，客户端不是不允许调用 bind()，只是没有必要调用 bind() 固定一个端口号，
    // 服务器也不是必须调用 bind()，但如果服务器不调用 bind()，内核会自动给服务器分配监听端口，
    // 每次启动服务器时端口号都不一样，客户端要连接服务器就会遇到麻烦。
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    write(sockfd, str, strlen(str));

    n = read(sockfd, buf, MAXLINE);
    printf("Response from server:\n");
    write(STDOUT_FILENO, buf, n);
    printf("\n");
    close(sockfd);
    return 0;
}