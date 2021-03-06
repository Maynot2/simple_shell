#include "hsh.h"

/**
 * _strlen - Computes the size of a string s.
 * @str: A pointer to a string.
 *
 * Return: The size as an integer.
 *
 */

int _strlen(char *str)
{
	int i;

	if (!str)
		return (0);

	i = 0;
	while (str[i])
		i++;

	return (i);
}


/**
 * _strcat - Concatenates 2 strings.
 * @dest: A pointer to a string.
 * @src: A pointer to a string.
 *
 * Return: The concatenated string on success.
 *         NULL on error.
 *
 */

char *_strcat(char *dest, char *src)
{
	char *result;
	int i, j;

	if ((!dest) && (!src))
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

/**
 * _strcmp - Compares if two string s1 and s2 are identical
 * @s1: A pointer to a string.
 * @s2: A pointer to a string.
 *
 * Return: 0 if string are identical.
 *         An integer equal to the difference between the ASCII code of
 *         the first different character
 *
 */

int _strcmp(char *s1, char *s2)
{
	int i, res = 0;
	int s1_len = _strlen(s1), s2_len = _strlen(s2);
	int longest = s1_len >= s2_len ? s1_len : s2_len;

	for (i = 0; i < longest; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _splitstr - Creates an array of strings from a string given e delimiter.
 * @str: A string.
 * @del: A string.
 *
 * Return: An array of strings.
 *
 **/

char **_splitstr(char *str, char *del)
{
	char **ary = NULL;
	char *token;
	int i, j;

	if (!str)
		return (NULL);

	ary = malloc(sizeof(char *) * (count_elems(str, del) + 1));
	if (!ary)
	{
		perror("Memory Allocation Error");
		return (NULL);
	}

	token = _strtok2(str, del);

	i = 0;
	while (token)
	{
		ary[i] = malloc(sizeof(char) * _strlen(token) + 1);

		j = 0;
		while (token[j])
		{
			ary[i][j] = token[j];
			j++;
		}
		ary[i][j] = '\0';

		token = _strtok2(NULL, del);
		i++;
	}
	ary[i] = NULL;
	return (ary);
}

/**
 * _strstr - Finds the first occurrence of the substring needle in string
 * haystack
 * @haystack: A pointer to a string.
 * @needle: A pointer to a string.
 *
 * Return: A pointer to a string on success.
 *         NULL on error
 *
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;
	int nd_len = _strlen(needle);

	if (!*needle)
		return (haystack);

	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if (nd_len - 1 == j)
			{
				return (haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
