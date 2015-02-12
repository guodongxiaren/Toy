#include "toy.h"

int main(int argc,char **argv){
    int sock;
    if((sock= socket(AF_INET,SOCK_STREAM,0)) < 0){
        err_exit("服务端创建套接字失败");
    }
    struct sockaddr_in sa;
    bzero(&sa,sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(SER_PORT);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock,(struct sockaddr *)&sa,(socklen_t)sizeof(sa)) < 0){
        err_exit("bind时错误");
    }

    listen(sock,5);
    struct sockaddr_in cliaddr;
    int len,connfd;
    char msg[256];
    int i=1;
    while(1){
        if((connfd = accept(sock,(struct sockaddr *)&cliaddr,&len)) < 0)
            err_exit("accept时错误");
        //bzero(msg,sizeof(msg));
        sprintf(msg,"hello %d\n",i++);
        write(connfd,msg,strlen(msg));
        close(connfd);
    }
}

