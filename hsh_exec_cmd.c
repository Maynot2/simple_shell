include "hsh.h"

/**
 * hsh_exec_cmd - exec a command 
 * @arguments: array of arguments
 * Return: Nothing
 **/
void hsh_exec_cmd(char **arguments)
{
	if (execve(arguments[0], arguments, NULL) == -1)
		perror("Execution Error\n");
}

