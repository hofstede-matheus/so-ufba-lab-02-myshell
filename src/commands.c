#include "commands.h"
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "errors.h"
#include <sys/wait.h> 

void commandStart(char *argv[], int argc) {
    printf("start\n");
    printf("%d\n", argc);

    char *args[argc];

    for (int i = 0; i < argc; i++) {
        args[i] = argv[i];
    }
    args[argc] = NULL;

    if (fork() == 0) {
        if (execvp(args[0], args) == -1) {
            switch (errno) {
                case EACCES:
                    errorPermission();
                    break;
                case ENOMEM:
                    errorMemory();
            }
        }
    }
}

void commandWait() {
    pid_t wpid;
    char mypid[6];

    printf("k\n");

    if(fork() == 0) {
        printf("child\n");
    } else {
        printf("!!\n");
        while ((wpid = wait(0)) > 0) {
            sprintf(mypid, "%d", wpid);
            printf("%s\n", mypid);
        }
    }

    /* if (fork() > 0) {
        printf("!!");
        while ((wpid = wait(0)) > 0) {
            sprintf(mypid, "%d", wpid);
            printf("%s\n", mypid);
        }
    } */



}