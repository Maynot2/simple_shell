#include "hsh.h"

int _strlen_strtok_delim(char *str, const char *delims, int *index)
{
	int j, k, ok;

	ok = 0;
	for (k = *index; str[k] != '\0'; k++)
	{
		for (j = 0; delims[j] != '\0'; j++)
		{
			if (str[k] == delims[j])
			{
				ok = 1;
			}
		}
		if (ok == 1)
		{
			break;
		}
	}

	return (k - *index);

}
