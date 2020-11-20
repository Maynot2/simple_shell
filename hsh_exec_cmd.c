#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command
 * @arguments: array of arguments
 * Return: Nothing
 */

int hsh_exec_cmd(char **arguments, char **env)
{
	int i;
	struct stat st;
	char **paths;
	pid_t id;

	paths = abs_cmd_paths(env, arguments[0]);

	id = fork();

	if (id == 0)
	{
		i = 0;
		while (paths[i])
		{
			if (stat(paths[i], &st) == 0)
			{
				arguments[0] = paths[i];
				if (execve(arguments[0], arguments, NULL) == -1)
				{
					perror(arguments[0]);
					kill(getpid(), SIGTERM);
				}
				return (1);
			}
			i++;
		}
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			perror(arguments[0]);
			kill(getpid(), SIGTERM);
		}
		return (1);
	}
	else
	{
		wait(NULL);
	}
}
