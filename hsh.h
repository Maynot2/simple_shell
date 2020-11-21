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
char **_splitstr(char *, char *);
int hsh_exec_cmd(char **, char **);
int _strlen(char *);
char *_strstr(char *, char *);
char *_strcat(char *, char *);
char **_splitstr(char *, char *);
int _strcmp(char *, char *);
char **formatcmd(char **, char *);
char **abs_cmd_paths(char **, char *);
int builtin(char *str); // to be removed
int hsh_builtins(char *, char **);
int hsh_exit(builtargs_t);
int hsh_env(builtargs_t);
void *_realloc(void *, unsigned int, unsigned int);
void free_str_ary(char **);
int arylen(char **);
int _putchar(char);
int _puts(char *s);

#endif
