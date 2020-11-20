#include "hsh.h"

int hsh_exec(char **args, char **env)
{
	if (hsh_builtins(args[0], env))
		return (hsh_builtins(args[0], env));

	return (hsh_exec_cmd(args, env));
}

int main(int argc, char **argv, char **envp)
{
	char **args;
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
	}
	free(line);
	free(args);
	return (0);
}
