#ifndef HSH_H
#define HSH_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include<signal.h>

/**
 * struct builtargs - Struct for arguments of builin functions.
 * @cmd: The name of the command
 * @env: The environement variables.
 *
 * Description: Same as above
 */

typedef struct builtargs
{
	char **cmd;
	char **env;
} builtargs_t;

/**
 * struct builtcmd - Struct to call a specific builtin function given the
 * matching comand.
 * @cmd: The name of the command.
 * @f: The matching function we want to call.
 *
 * Description: Same as above
 */

typedef struct builtcmd
{
	char *cmd;
	int (*f)(builtargs_t);
} builtcmd_t;

void display_prompt(void);
int hsh_exec_cmd(char **, char **);
int _strlen(char *);
char *_strstr(char *, char *);
char *_strcat(char *, char *);
char **_splitstr(char *, char *);
int _strcmp(char *, char *);
char **formatcmd(char **, char *);
char **abs_cmd_paths(char **, char *);
int hsh_builtins(char **, char **);
int hsh_exit(builtargs_t);
int hsh_env(builtargs_t);
void *_realloc(void *, unsigned int, unsigned int);
void free_str_ary(char **, int);
int arylen(char **);
int _putchar(char);
int _puts(char *s);
int count_elems(char *, char *);
int isdel(char, const char*);
char *_strtok1(char *, const char *);
char *_strtok2(char *, const char *);
void handle_sigint(int);
char *_strdup(char *);
int hsh_cd(builtargs_t);

#endif
