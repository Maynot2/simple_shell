#include "hsh.h"

int builtin(char *str)
{
	type_d cases[] = {
		{"exit", hsh_exit}, {"env", hsh_env},
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
			cases[i].f();
		}
		i++;
	}
	return (0);
}
