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
	int ret;

	ret = (hsh_builtins(args, env));
	if (ret)
		return (ret);

	return (hsh_exec_cmd(args, env));
}

/**
  * handle_sigint - Prints new line and redisplay prompt after signal
  * inturption is triggered by ctrl-c
  * @sig: An integer.
  *
  * Return nothing.
  */

void handle_sigint(int sig)
{
	(void)sig;

	_putchar('\n');
	if (isatty(STDIN_FILENO))
		display_prompt();
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
	(void)argc;
	(void)argv;

	while (status != -1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		signal(SIGINT, handle_sigint);
		if (getline(&line, &size, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
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
