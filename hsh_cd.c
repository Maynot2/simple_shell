#include "hsh.h"

/**
 * hsh_cd - function to change directory
 * @args: struct to command and env
 * Return: 1 when it works
 **/

int hsh_cd(builtargs_t args)
{
	char *dir;
	int i, j;
	size_t size;

	size = _strlen(args.cmd[1]);
	if (args.cmd[1] == "-")
	{
		if (chdir(dir) != 0)
			perror(dir);
	}
	else if (args.cmd[1])
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
