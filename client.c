#include "toy.h"
char *ip = "127.0.0.1";
int main(int argc,char **argv){

    int sock;
    if((sock = socket(AF_INET,SOCK_STREAM,0)) < 0){
        err_exit("客户端创建套接字错误");
    }
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(SER_PORT);
    inet_pton(AF_INET,ip,&sa.sin_addr);

    if(connect(sock,(struct sockaddr *)&sa,(socklen_t)sizeof(sa)) < 0){
        printf("%d\n",errno);
        err_exit("connect错误");
    }
    char msg[256];
    while(1){
        scanf("%s",msg);
        if(write(sock,msg,sizeof(msg)) <= 0)
            continue;
        bzero(msg,sizeof(msg));
        if(read(sock,msg,256*sizeof(char)) > 0)
            printf("%s\n",msg);
    }
    
}

