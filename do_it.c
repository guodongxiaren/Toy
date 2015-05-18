#include "server.h"

char msg[256];

char *do_it(char* cmd)
{
    int pid;
    if ((pid = fork()) < 0)
    {
        err_exit("fork error");
    }
    if (pid == 0)
    {
        printf("\n;");
        //execvp(cmd[1], &cmd[1]); 
        system(cmd);
        printf("\n;");
    }
    else
    {
        fscanf(stdout, "%s", msg);
        printf(":%s:\n",msg);
    }
    return NULL;
}

