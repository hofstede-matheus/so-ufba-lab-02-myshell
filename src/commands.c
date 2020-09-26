#define _POSIX_SOURCE

#include "commands.h"
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "errors.h"
#include <sys/wait.h> 
#include <stdlib.h>
#include <string.h>

void commandStart(char *argv[], int argc) {
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

    if((fork() == 0)) {
        printf("child\n");
        sleep(1);
        kill(getpid(), SIGKILL);
    } else {
        printf("!!\n");
        int corpse;
        int status;
        int childrenCount = 0;

        while ((corpse = waitpid(0, &status, 0)) > 0) {
            childrenCount++;
            if (status == 0) printf("myshell: processo %d finalizou normalmente com status %d.\n", corpse, status);
            else {
                char * signalDescription;
                if (status == 1) signalDescription = "SIGHUP";
                else if (status == 2) signalDescription = "SIGINT";
                else if (status == 3) signalDescription = "SIGQUIT";
                else if (status == 4) signalDescription = "SIGILL";
                else if (status == 5) signalDescription = "SIGTRAP";
                else if (status == 6) signalDescription = "SIGABRT";
                else if (status == 7) signalDescription = "SIGEMT";
                else if (status == 8) signalDescription = "SIGFPE";
                else if (status == 9) signalDescription = "SIGKILL";

                printf("myshell: processo %d finalizou de forma anormal com sinal %d: %s..\n", corpse, status, signalDescription);
            }
        }
        if (childrenCount == 0) printf("myshell: não há processos restantes.");
    }

    /* if (fork() > 0) {
        printf("!!");
        while ((wpid = wait(0)) > 0) {
            sprintf(mypid, "%d", wpid);
            printf("%s\n", mypid);
        }
    } */



}