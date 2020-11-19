#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command
 * @arguments: array of arguments
 * @environ: extern char env
 * Return: Nothing
 */

int hsh_exec_cmd(char **arguments, char **environ)
{

	int i;
	struct stat st;
	char **paths = array_PATH(environ, arguments);

	if (!arguments[0])
		kill(getpid(), SIGTERM);

	i = 0;
	while (paths[i])
	{
		if (stat(paths[i], &st) == 0)
		{
			arguments[0] = paths[i];
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror(arguments[0]);
				free_arr(arguments);
				free_arr(paths);
				kill(getpid(), SIGTERM);
			}
		}
		i++;
	}
	if (execve(arguments[0], arguments, NULL) == -1)
	{
		perror(arguments[0]);
		free_arr(arguments);
		free_arr(paths);
		kill(getpid(), SIGTERM);
	}
	return (0);
}
