#include "hsh.h"

/**
 * hsh_readline - readline from stdin
 * Return: nothing
 **/

char *hsh_readline(void)
{
	char *buffer[1] = {NULL};
	ssize_t size = 1;

	if (getline(buffer, &size, stdin) == EOF)
		return (NULL);
	return (buffer[0]);
}
