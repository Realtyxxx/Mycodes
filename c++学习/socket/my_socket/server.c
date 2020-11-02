#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;

    // socket() 打开一个网络通讯端口，如果成功的话，
    // 就像 open() 一样返回一个文件描述符，
    // 应用程序可以像读写文件一样用 read/write 在网络上收发数据。
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    // bind() 的作用是将参数 listenfd 和 servaddr 绑定在一起，
    // 使 listenfd 这个用于网络通讯的文件描述符监听 servaddr 所描述的地址和端口号。
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // listen() 声明 listenfd 处于监听状态，
    // 并且最多允许有 20 个客户端处于连接待状态，如果接收到更多的连接请求就忽略。
    listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1)
    {
        cliaddr_len = sizeof(cliaddr);
        // 典型的服务器程序可以同时服务于多个客户端，
        // 当有客户端发起连接时，服务器调用的 accept() 返回并接受这个连接，
        // 如果有大量的客户端发起连接而服务器来不及处理，尚未 accept 的客户端就处于连接等待状态。
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
      
        n = read(connfd, buf, MAXLINE);
        printf("received from %s at PORT %d\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
               ntohs(cliaddr.sin_port));
    
        for (i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
            
        write(connfd, buf, n);
        close(connfd);
    }
}