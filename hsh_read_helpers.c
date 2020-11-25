#include "hsh.h"

/**
 * isdel - Tests if a given character c is a delimeter.
 * @c: A given character.
 * @dels: A set of delimiters as a string.
 *
 * Return: 1 on success.
 *         0 on error.
 *
 */

int isdel(char c, const char *dels)
{
	int i;

	i = 0;
	while (dels[i])
	{
		if (c == dels[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * count_elems - Counts elements of a string str separated by a given set of
 * delimiters dels.
 * @str: A given string.
 * @dels: A string of delimiters.
 *
 * Return: The number of elements.
 */

int count_elems(char *str, char *dels)
{
	int i;
	int count = 0;

	i = 0;
	while (str[i])
	{
		if (i == 0 && !isdel(str[i], dels))
			count++;
		if (i != 0)
		{
			if (!isdel(str[i], dels) && isdel(str[i - 1], dels))
				count++;
		}
		i++;
	}
	return (count);
}
