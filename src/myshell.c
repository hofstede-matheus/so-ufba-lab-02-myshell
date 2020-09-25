#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <errno.h>
#include "errors.h"

#include "commands.h"

#define EXPECTED_ARGUMENTS 2 /* program name + 1 arguments */
#define BUFFER_SIZE 256
#define TRUE 1

int strEquals(char *s1, char *s2) {
    if (strcmp(s1, s2) == 0)
        return 1;
    else
        return 0;
}

char *concatString(const char *str1, const char *str2) {
    size_t s1, s2, s3, i = 0;
    char *a;

    s1 = strlen(str1);
    s2 = strlen(str2);
    s3 = s1 + s2 + 1;
    a = malloc(s3);

    while (*str1 != '\0')
    {
        a[i] = *str1;
        str1++;
        i++;
    }
    while (*str2 != '\0')
    {
        a[i] = *str2;
        str2++;
        i++;
    }

    a[i] = '\0';
    return a;
}

void invoke(char *command, char *argv[], int argc) {

    if(strEquals(command, "start")) {
        commandStart(argv, argc);
    } else if (strEquals(command, "wait")) {
        commandWait();
    }

}

int main(int argc, char **argv) {

    char buffer[BUFFER_SIZE];
    char *token;

    char *palavras[100];
    int npalavras = 0;
    char *command;

    while (TRUE) {
        npalavras = 0;
        printf("myshell> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        token = strtok(buffer, " \t\n");

        command = token;

        token = strtok(NULL, " \t\n");

        while (token != NULL) {
            // printf("'%s'\n", token);
            palavras[npalavras] = token;
            npalavras++;
            token = strtok(NULL, " \t\n");
        }
        palavras[npalavras] = 0;

        // while( token != NULL ) {
        //     token = strtok(NULL, delimiter);
        //     // printf("%s:::%s\n", token, arguments);
        //     printf("!!\n%s\n", concatString(arguments, token));
        //     printf("!!\n%s\n", concatString(arguments, token));
        //     /* strcat(arguments, token);
        //     arguments = concatString(arguments, token); */

        // }

        // for (int i = 0; i < npalavras; i++) {
        //     printf("%s \n", palavras[i]);
        // }

        invoke(command, palavras, npalavras);

    }

    return EXIT_SUCCESS;
}
