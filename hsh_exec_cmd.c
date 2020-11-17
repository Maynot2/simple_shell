#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command 
 * @arguments: array of arguments
 * Return: Nothing
 */

void hsh_exec_cmd(char **arguments)
{
	int i = 0;
	struct stat st;
	char extern **environ;
	char **arr = array_PATH(environ, arguments);

	if (arguments[0] != NULL)
	{
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			while (arr[i])
			{
				if (stat(arr[i], &st) == 0)
				{
					arguments[0] = arr[i];
					if (execve(arguments[0], arguments, NULL) == -1)
					{
						perror("Execution Error\n");
						kill(getpid(), SIGTERM);
					}
				}
				i++;
			}
		}
	}
	kill(getpid(), SIGTERM);
}

