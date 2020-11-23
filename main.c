#include "hsh.h"

/**
  * hsh_exec - Executes a builtin command or a shell command.
  * @args: The arguments of the command to be executed.
  * @env: The environement variables as an array.
  *
  * Return: 1 on success.
  *         0 on error.
  *        -1 when exited.
  */

int hsh_exec(char **args, char **env)
{
	if (hsh_builtins(args[0], env))
		return (hsh_builtins(args[0], env));

	return (hsh_exec_cmd(args, env));
}

/**
  * main - Starts the simple shell.
  * @argc: The number of arguments passed to the program.
  * @argv: The arguments passed to the program as an array.
  * @envp: The environement variables as an array.
  *
  * Return: Always 0;
  *
  */

int main(int argc, char **argv, char **envp)
{
	char **args = NULL;
	char *line = NULL;
	size_t size = 0;
	int status = 1;

	while (status != -1)
	{
		display_prompt();
		if (getline(&line, &size, stdin) == -1)
		{
			_putchar('\n');
			break;
		}
		args = _splitstr(line, " \t\r\n\v\f");
		if (args[0])
			status = hsh_exec(args, envp);
		free_str_ary(args, arylen(args));
	}
	free(line);
	return (0);
}
