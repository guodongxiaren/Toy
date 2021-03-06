#ifndef _TOY_H
#define _TOY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <netinet/in.h>    
#include <sys/types.h>    
#include <sys/socket.h>    
#include <arpa/inet.h>    

//常数宏
#define SER_PORT 2121    //服务器端口
//定义TCP和UDP连接
#define TCP 0x01
#define UDP 0x02

//函数声明
int sock_service(int _type);
//自定义函数
void err_exit(char *err);
#endif
