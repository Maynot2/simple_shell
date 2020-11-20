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
