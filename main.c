#include "hsh.h"


/**
 * main - main function of the hsh shell
 * @argc: number of arguments
 * @argv: char table of arguments
 * @envp: externe char environ
 * Return: 0 when it works
 **/

int main(int argc, char *argv[], char *envp[])
{
	char **args;
	char *line;
	int status = 1;
	pid_t id;

	while (status)
	{
		display_prompt();
		line = hsh_readline();
		args = splitstr(line);
		hsh_exit(args);
		id = fork();
		if (id == 0)
		{
			builtin(args[0], envp);
			hsh_exec_cmd(args, envp);
			free(line);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
