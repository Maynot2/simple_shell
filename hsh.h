#ifndef HSH_H
#define HSH_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void display_prompt(void);
char **splitstr(char *);
char *hsh_readline(void);
void hsh_exec_cmd(char **);
int _strlen(char *);
char **splitstr(char *);

#endif
