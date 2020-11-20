#include "hsh.h"

/**
 * _strlen - Computes the size of a string s.
 * @s: A pointer to a string.
 *
 * Return: the size as an integer.
 *
 */

int _strlen(char *str)
{
	int i;

	if (!str)
		return (0);

	i = 0;
	while(str[i])
		i++;

	return (i);
}

char *_strcat(char *dest, char *src)
{
	char *result;
	int i, j;

	if ((!des)t && (!src))
		return (NULL);

	result = malloc(sizeof(char) * _strlen(dest) + _strlen(src) + 1);
	if (!result)
		return (NULL);

	i = 0;
	while (dest[i])
	{
		result[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		result[i + j] = src[j];
		j++;
	}
	result[i + j] = '\0';

	return (result);
}
