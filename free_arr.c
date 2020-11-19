#include "hsh.h"


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
