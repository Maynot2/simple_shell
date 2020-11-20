#include "hsh.h"

/**
  * arylen - Computes the number of elements in a NULL terminated array of
  * strings.
  * @ary: An array of strings.
  *
  * Return: The number of elements in an array.
  *
  */

int arylen(char **ary)
{
	int i = 0;

	if (!ary)
		return (0);

	while (ary[i])
		i++;
	return (i);
}
