#include "server.h"
#include "do_it.c"

int main(int argc, char **argv)
{
    int sock;
    sock = sock_service(TCP);
    if ((sock= socket(AF_INET, SOCK_STREAM,0)) < 0)
    {
        err_exit("服务端创建套接字失败");
    }
    struct sockaddr_in sa;
    bzero(&sa,sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(SER_PORT);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&sa, (socklen_t)sizeof(sa)) < 0)
    {
        err_exit("bind时错误");
    }

    listen(sock,5);
    struct sockaddr_in cliaddr;
    int len, connfd;
    char msg[256];
    int i = 1;
    while (1)
    {
        if ((connfd = accept(sock, (struct sockaddr *)&cliaddr, &len)) < 0)
            err_exit("accept时错误");
        bzero(msg,sizeof(msg));
        while (1) 
        {
            read(connfd, msg, sizeof(msg));
            printf("recv:%s\n", msg);
            char *msg2 = do_it(msg); 
            if (!msg2)
            {
                printf("client left.\n");
                break;
            }
            //printf("send:%s\n", msg2);
            //write(connfd, msg2, strlen(msg2));
        }
        close(connfd);
    }
}
