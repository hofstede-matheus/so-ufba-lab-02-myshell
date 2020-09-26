#ifndef COMMANDS_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define COMMANDS_H

void commandStart(char *argv[], int argc);
void commandWait();
void commandChdir(char *path);
void commandWatchdog(char *argv[], int argc);

#endif