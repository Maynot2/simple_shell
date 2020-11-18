#include "hsh.h"

void hsh_env()
{
	int i, j;
	char extern **environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		for(j = 0; environ[i][j] != '\0'; j++)
		{
			putchar(environ[i][j]);
		}
		putchar('\n');
	}
}
