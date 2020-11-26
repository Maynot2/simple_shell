#include "hsh.h"



/**
 * getPATH - Finds the path of the current environement.
 * @env: An array of all the environement variables.
 *
 * Return: The path as a string.
 */

char *getPATH(char **env)
{
	int i = 0, j, k;
	char *path = NULL;

	if(!env)
		return (NULL);

	while (env[i])
	{
		if (_strstr(env[i], "PATH=/") && env[i][0] == 'P')
		{
			path = malloc(sizeof(*path) * (_strlen(env[i]) + 1 - 5));
			if (!path)
			{
				perror("Memory Allocation Error");
				return (NULL);
			}
			k = 0;
			while (env[i][k] != '=')
				k++;
			k++;
			j = 0;
			while (env[i][j + k])
			{
				path[j] = env[i][j + k];
				j++;
			}
			path[j] = '\0';
		}
		i++;
	}
	return (path);
}
/**
 * formatcmd - concat path env to an array
 * @paths: An array of directories absolute paths.
 * @arg: the command.
 * Return: a new 2D array
 **/

char **formatcmd(char **paths, char *arg)
{
	int i, j, k, lenpath, lenarg;
	char **ary;

	if(!paths)
		return (NULL);

	ary = malloc(sizeof(char *) * (arylen(paths) + 1));
	if (!ary)
	{
		perror("Memory Allocation Error");
		return (NULL);
	}

	for (i = 0; paths[i] != NULL; i++)
	{
		lenpath = _strlen(paths[i]);
		lenarg = _strlen(arg);

		ary[i] = malloc(sizeof(char) * (lenpath + lenarg + 2));
		if (!ary[i])
		{
			perror("Memory Allocation Error");
			free_str_ary(ary, i);
		}
		for (j = 0; j != lenpath; j++)
		{
			ary[i][j] = paths[i][j];
		}
		ary[i][j] = '/';
		j++;
		for (k = 0; arg[k] != '\0'; k++)
		{
			ary[i][j] = arg[k];
			j++;
		}
		ary[i][j] = '\0';
	}
	ary[i] = NULL;
	return (ary);
}

/**
 * abs_cmd_paths - Builds the different possible absolute path for a command.
 * @env: An array of all the environement variables.
 * @cmd: The command we want to try.
 *
 * Return: An array of all the possible paths.
 */

char **abs_cmd_paths(char **env, char *cmd)
{
	char *path;
	char **dirs;
	char **cmds;

	path = getPATH(env);
	dirs = _splitstr(path, ":");
	cmds = formatcmd(dirs, cmd);
	free(path);
	free_str_ary(dirs, arylen(dirs));
	return (cmds);
}

/**
  * exec_cmd - Executes a command and deals with the failure if cmd cannot
  * execute.
  * @arguments: The command arguments.
  *
  * Return: Nothing.
  */

void exec_cmd(char **arguments)
{
	if (execve(arguments[0], arguments, NULL) == -1)
	{
		perror(arguments[0]);
		kill(getpid(), SIGTERM);
	}
}

/**
 * hsh_exec_cmd - exec a command
 * @arguments: array of arguments
 * @env: An array of all the environement variables.
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
		if (!paths)
			exec_cmd(arguments);
		i = 0;
		while (paths[i])
		{
			if (stat(paths[i], &st) == 0)
			{
				arguments[0] = _strdup(paths[i]);
				free_str_ary(paths, arylen(paths));
				exec_cmd(arguments);
				return (1);
			}
			i++;
		}
		free_str_ary(paths, arylen(paths));
		exec_cmd(arguments);
		return (1);
	}
	else
	{
		free_str_ary(paths, arylen(paths));
		wait(NULL);
		return (1);
	}
}
