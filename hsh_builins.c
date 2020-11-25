#include "hsh.h"

/**
 * hsh_builtins - Calls the right builtin cmd.
 * @cmd: The command to be called
 * @env: The current environement.
 *
 * Return: 1 if a cmd was called successfully.
 *         0 if no cmd was called.
 *        -1 if exit was called.
 */

int hsh_builtins(char **cmd, char **env)
{
	int i;
	builtargs_t args;
	builtcmd_t cmds[] = {
		{"exit", hsh_exit}, {"cd", hsh_cd},
		{"env", hsh_env},
		{NULL, NULL}
	};

	args.cmd = cmd;
	args.env = env;

	i = 0;
	while (cmds[i].cmd)
	{
		if (_strcmp(cmd[0], cmds[i].cmd) == 0)
		{
			return (cmds[i].f(args));
		}
		i++;
	}
	return (0);
}

/**
 * hsh_exit - Exits hsh.
 * @args: A structure.
 *
 * Return: Always -1
 */

int hsh_exit(builtargs_t args)
{

	(void)args;

	return (-1);
}

/**
 * hsh_env - Prints current environement.
 * @args: A structure.
 *
 * Return: Always 1.
 */

int hsh_env(builtargs_t args)
{
	int i;

	i = 0;
	while (args.env[i])
	{
		_puts(args.env[i]);
		i++;
	}
	return (1);
}
