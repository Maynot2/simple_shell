#include "hsh.h"
/**
 * splitstr - create an array from a string
 * @str: a string
 * Return: an array
 **/

char **_splitstr(char *str, char *del)
{
	char **ary;
	char **tmp;
	char *token;
	int i, j;
	int size = 8;

	ary = malloc(sizeof(char *) * size);
	if (!ary)
		exit(1);

	token = strtok(str, del);

	i = 0;
	while (token)
	{
		if (i >= size - 1)
		{
			size += size;
			tmp = realloc(ary, sizeof(char *) * size);
			ary = tmp;
		}
		ary[i] = malloc(sizeof(char) * strlen(token));
		if (ary[i] == NULL)
		{
			for(j = 0; j < i; j++)
				free(ary[j]);
			free(ary);
		}

		ary[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	ary[i] = NULL;
	return (ary);
}
