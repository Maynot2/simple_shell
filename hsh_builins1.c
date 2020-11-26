#include "hsh.h"

/**
 * hsh_unsetenv - unset a environnement variable
 * @args: struct on args
 * Return: 1
 **/

int hsh_unsetenv(builtargs_t args)
{
	int i, j;

	if (args.cmd[1])
	{
		i = 0;
		while (_strstr(args.env[i], args.cmd[1]) == NULL && args.env[i + 1] != NULL)
			i++;
		j = 0;
		if (_strstr(args.env[i], args.cmd[1]) != NULL)
			args.env[i][j] = '\0';
	}
	return (1);
}
