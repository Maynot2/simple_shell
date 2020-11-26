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
		{"env", hsh_env}, {"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv}, {NULL, NULL}
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

/**
 * hsh_cd - function to change directory
 * @args: struct to command and env
 * Return: 1 when it works
 **/

int hsh_cd(builtargs_t args)
{
	int i, j;

	if (args.cmd[1])
	{
		if (chdir(args.cmd[1]) != 0)
			perror(args.cmd[1]);
	}
	else
	{
		for (i = 0; _strstr(args.env[i], "HOME=") == NULL; i++)
			;
		for (j = 0; args.env[i][j] != '='; j++)
			;
		j++;
		if (chdir(&args.env[i][j]) != 0)
			perror(&args.env[i][j]);
	}

	return (1);
}

/**
 * hsh_setenv - set an environnement variable
 * @args: struct on args
 * Return: 0 when it works
 **/

int hsh_setenv(builtargs_t args)
{
	int i, j, k;

	if (args.cmd[1] && args.cmd[2])
	{
		i = 0;
		while (_strstr(args.env[i], args.cmd[1]) == NULL && args.env[i + 1] != NULL)
			i++;
		if (_strstr(args.env[i], args.cmd[1]) != NULL)
		{
			for (j = 0; args.env[i][j] != '='; j++)
				;
			j++;

			k = 0;
			for (; args.cmd[2][k] != '\0'; k++)
			{
				args.env[i][j] = args.cmd[2][k];
				j++;
			}
			args.env[i][j] = '\0';
		}
	}
	return (1);
}
