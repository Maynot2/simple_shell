#include "hsh.h"

/**
 * array_PATH - concat path env to an array
 * @env: the env vars
 * @buf: the array
 * Return: a new 2D array
 **/

char **array_PATH(char **env, char **buf)
{
	int j, k, l = 0;
	char *delim = ":=";
	char *token;
	char **arr;


	for (j = 0; strstr(env[j], "PATH=") == NULL ; j++)
	;
	for (k = 0; env[j][k] != '\0'; k++)
	{
		if (env[j][k] == ':')
		{
			l++;
		}
	}
	token = strtok(env[j], delim);
	arr = malloc(sizeof(char *) * k);
	token = strtok(NULL, delim);
	for (j = 0; token != NULL; token = strtok(NULL, delim))
	{
		arr[j] = malloc(sizeof(char) * (_strlen(token) + _strlen(*buf) + 2));
		for (k = 0; k < _strlen(token); k++)
			arr[j][k] = token[k];
		arr[j][k] = '/';
		k++;
		l = 0;
		for (; k <= (_strlen(token) + _strlen(*buf)) ; k++)
		{
			arr[j][k] = (*buf)[l];
			l++;
		}
		arr[j][k] = '\0';
		j++;
	}
	return (arr);
}
