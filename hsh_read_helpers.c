#include "hsh.h"

/**
  * isdel - Tests if a given character c is a delimeter.
  * @c: - A given character.
  *
  * Return: 1 on success.
  *         0 on error.
  *
  */

int isdel(char c)
{
	char dels[] = " \t\r\n\v\f";
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
	int i, j;
	int count = 0;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (dels[j])
		{
			if (str[i] == dels[j] && !isdel(str[i + 1]))
			{
				count++;
				break;
			}
			j++;
		}
		i++;
	}
	if (isdel(str[i - 1]))
		return (count);
	else
		return (count + 1);
}
