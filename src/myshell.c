#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <errno.h>
#include "errors.h"

#define EXPECTED_ARGUMENTS 2 /* program name + 1 arguments */
#define BUFFER_SIZE 4096 /* buffer 4MB */

int strEquals(char * s1, char * s2) {
    if (strcmp(s1, s2) == 0) return 1;
    else return 0;
}

int main(int argc, char ** argv){

    if (argc == EXPECTED_ARGUMENTS) {

        if (strEquals(argv[1], "start")) {
            printf("start \n");
            
        } else if ("wait") {
            printf("wait \n");

        } else if ("waitfor") {
            printf("waitfor \n");

        } else if ("run") {
            printf("run \n");
            
        } else if ("watchdog") {
            printf("watchdog \n");

        } else if ("chdir") {
            printf("chdir \n");

        } else if ("quit") {
            printf("quit \n");

        } else if ("exit") {
            printf("exit \n");

        } else {

        }
        /* TODO: Caso linha em branco */


    } else {
        errorInvalidArgumentsNumber();
    }

   return EXIT_SUCCESS;
}

