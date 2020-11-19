#include "hsh.h"

/**
 * hsh_exit - exit builtin function
 * @str: an input string
 * Return: nothing
 **/

void hsh_exit(char **str)
{
	char *result = "exit";
	int ex = 1;
	int i;

	if (_strlen(str[0]) >= 1)
	{
		for (i = 0; str[0][i] != '\0'; i++)
		{
			if (str[0][i] != result[i])
			{
				ex = 0;
			}
		}
		if (ex == 1)
			exit(0);
	}
}
