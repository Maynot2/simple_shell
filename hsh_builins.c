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

/**
 * hsh_cd - function to change directory
 * @args: struct to command and env
 * Return: 1 when it works
 **/

int hsh_cd(builtargs_t args)
{
	char *dir;
	int i;
	size_t size;

	size = _strlen(args.cmd[1]);
	if (args.cmd[1])
	{
		if (chdir(args.cmd[1]) != 0)
			perror(args.cmd[1]);
		dir = malloc(sizeof(char) * (size + 1));
		dir = args.cmd[1];
		getcwd(dir, size);
	}
	else
	{
		for (i = 0; _strstr(args.env[i], "HOME=") == NULL; i++)
		;
		dir = malloc(sizeof(char) * (_strlen(args.env[i]) + 1));
		dir = args.env[i];
		dir = _strtok2(dir, "=");
		dir = _strtok2(NULL, "=");
		if (chdir(dir) != 0)
			perror(dir);
		getcwd(dir, size);
		args.env[i][4] = '=';
	}

	return (1);
}
