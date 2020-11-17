#include "hsh.h"
/**
 * splitstr - create an array from a string
 * @str: a string
 * Return: an array 
 **/

char **splitstr(char *str)
{
	char **ary;
	char *token;
	char *del = " \t\r\n\v\f";
	int i, j;
	int size = 8;

	if (!str)
		return (NULL);

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
			ary = realloc(ary, sizeof(char *) * size);
		}
		ary[i] = malloc(sizeof(char) * _strlen(token));
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
	return ary;
}
