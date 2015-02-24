#include "toy.h"
void err_exit(char *err){
    perror(err);
    exit(EXIT_FAILURE);
}

