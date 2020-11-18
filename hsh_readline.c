#include "hsh.h"

/**
 * hsh_readline - readline from stdin
 * Return: nothing
 **/

char *hsh_readline(void)
{
	char *buffer[0];
	ssize_t size = 0;

	if (getline(buffer, &size, stdin) == EOF)
		exit(0);
	return (buffer[0]);
}
