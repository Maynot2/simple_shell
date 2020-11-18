#include "hsh.h"

/**
 * hsh_env - print the environnements vars
 * @environ: extern var env
 * Return: None
 **/

void hsh_env(char **environ)
{

	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			putchar(environ[i][j]);
		}
		putchar('\n');
	}
	kill(getpid(), SIGTERM);
}
