#include "hsh.h"

/**
  * _strlen - Computes the size of a string s.
  * @s: A pointer to a string.
  *
  * Return: A integer.
  *
  */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (i);

	while (s[i])
		i++;

	return (i);
}
