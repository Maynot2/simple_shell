#include "hsh.h"

/**
 * array_PATH - concat path env to an array
 * @env: the env vars
 * @buf: the array
 * Return: a new 2D array
 **/

char **array_PATH(char **env, char **buf)
{
	int i, j, k, l, len_token, len_buf, len_tot;
	char *delim = ":=";
	char *token;
	char **arr;


	for (i = 0; strstr(env[i], "PATH=") == NULL ; i++)
	;

	arr = malloc(sizeof(char *) * 15);

	token = strtok(env[i], delim);
	token = strtok(NULL, delim);
	len_buf = strlen(*buf);

	for (j = 0; token != NULL; token = strtok(NULL, delim))
	{
		len_token = strlen(token);
		len_tot = (len_token + len_buf);
		arr[j] = malloc(sizeof(char) * 1000);
		for (k = 0; k < len_token; k++)
			arr[j][k] = token[k];
		arr[j][k] = '/';
		k++;
		l = 0;
		for (; k <= len_tot ; k++)
		{
			arr[j][k] = (*buf)[l];
			l++;
		}
		arr[j][k] = '\0';
		j++;
	}
	return (arr);
}

