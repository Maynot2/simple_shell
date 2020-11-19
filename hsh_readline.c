#include "hsh.h"

/**
 * hsh_readline - readline from stdin
 * Return: nothing
 **/

char *hsh_readline(char **line)
{
	ssize_t size = 0;

	signal(SIGINT, hsh_sigint);

	if (getline(line, &size, stdin) == EOF)
		exit(0);

	return (*line);
}
