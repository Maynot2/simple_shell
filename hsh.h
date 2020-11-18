#ifndef HSH_H
#define HSH_H

#define UNUSED(x) (void)x;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct format
{
	char *type;
	void (*f)();
} type_d;

void display_prompt(void);
char **splitstr(char *);
char *hsh_readline(void);
void hsh_exec_cmd(char **arguments, char **envp);
int _strlen(char *);
char **splitstr(char *);
char **array_PATH(char **env, char **buf);
int builtin(char *str, char **environ);
void hsh_exit(char *str);
void hsh_env(char **environ);

#endif
