#include "hsh.h"

/**
 * hsh_exec_cmd - exec a command 
 * @arguments: array of arguments
 * Return: Nothing
 */

int hsh_exec_cmd(char **arguments)
{
	if (!arguments)
		return (0);

	if (execve(arguments[0], arguments, NULL) == -1)
		perror("Execution Error\n");
	return (1);
}

