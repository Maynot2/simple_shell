#include "hsh.h"

int hsh_exec(char **args, char **env)
{
	if (hsh_builtins(args[0], env))
		return (hsh_builtins(args[0], env));

	return (hsh_exec_cmd(args, env));
}

int hsh_exit(builtargs_t args)
{
	if (strcmp(args.cmd, "exit") == 0)
			return (-1);
	return (0);
}

int hsh_env(builtargs_t args)
{
		int i;

		i = 0;
		while(args.env[i])
		{
			puts(args.env[i]);
			i++;
		}
	return(1);
}

int hsh_builtins(char *cmd, char **env)
{
	int i;
	builtargs_t args = {
		cmd,
		env
	};
	builtcmd_t cmds[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{NULL, NULL}
	};

	i = 0;
	while (cmds[i].cmd)
	{
		if (strcmp(cmd, cmds[i].cmd) == 0)
		{
			return (cmds[i].f(args));
		}
		i++;
	}
	return (0);
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
