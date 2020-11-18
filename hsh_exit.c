#include "hsh.h"

void hsh_exit(char *str)
{
	char *result = "exit";
	int ex = 1;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != result[i])
		{
			ex = 0;
		}
	}
	if (ex == 1)
		exit(0);
}
