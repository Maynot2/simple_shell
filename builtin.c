#include "hsh.h"

/**
 * builtin - call the right builtin function
 * @str: the built in command to call
 * @environ: environnement variables
 * Return: 0 if it works
 **/

int builtin(char *str, char **environ)
{
	type_d cases[] = {
		{"env", hsh_env},
		{NULL, NULL}};

	int i, j, same;

	same = 0;
	i = 0;
	while (cases[i].type)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			if (str[j] == cases[i].type[j])
				same = 1;
			else
			{
				same = 0;
				break;
			}
		}
		if (same)
		{
			cases[i].f(environ);
		}
		i++;
	}
	return (0);
}
