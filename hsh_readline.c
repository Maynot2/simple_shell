#include "hsh.h"

/**
 * hsh_readline - readline from stdin
 * Return: nothing
 **/

char *hsh_readline(void)
{
	char *buffer[1] = {NULL};
	ssize_t size = 1;

	if (getline(buffer, &size, stdin) == -1) // read line
		perror("Read Error\n");
	return (buffer[0]);
}
