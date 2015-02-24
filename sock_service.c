#include "toy.h"
int sock_service(int _type){
    int type,sock;
    switch(_type){
        case TCP : type = SOCK_STREAM;
            break;
        case UDP : type = SOCK_DGRAM;
            break;
        default:
            err_exit("套接字类型错误");
    }
    if((sock = socket(AF_INET,type,0)) < 0){
        err_exit("创建套接字失败");
    }
    return sock;
}

