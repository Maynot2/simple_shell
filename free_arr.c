#include "hsh.h"

/**
 * free_arr - free an array
 * @arr: a 2D array
 * Return: Nothing
 **/

void free_arr(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
}
