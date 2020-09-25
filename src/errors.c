#include <stdlib.h>
#include "errors.h"
#include <stdio.h>

void errorInvalidArgumentsNumber() {
    printf("Número de argumentos inválidos \n");
    exit(EXIT_FAILURE);
}

void errorPermission() {
    printf("myshell: Permissão negada! \n");
    exit(EXIT_FAILURE);
}

void errorMemory() {
    printf("myshell: Sem memória suficiente! \n");
    exit(EXIT_FAILURE);
}