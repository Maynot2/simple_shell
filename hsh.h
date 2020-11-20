#ifndef HSH_H
#define HSH_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct builtargs
{
	char *cmd;
	char **env;
} builtargs_t;

typedef struct builtcmd
{
	char *cmd;
	int (*f)(builtargs_t);
} builtcmd_t;

void display_prompt(void);
char **splitstr(char *);
int hsh_exec_cmd(char **, char **);
int _strlen(char *);
char *_strcat(char *, char *);
char **_splitstr(char *, char *);
char **abs_cmd_paths(char **, char *);
int builtin(char *str);
int hsh_exit(builtargs_t);
int hsh_env();

#endif
