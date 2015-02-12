#include "server.h"

char msg[256];
static void pwd();
char *do_it(const char* cmd){

    if(strcmp(cmd,"pwd") == 0){
        pwd();
    }
    return msg;
}

static void pwd(){
    if(getcwd(msg,sizeof(msg)) == NULL){
        perror("错误");
    }
} 

