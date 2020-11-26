#include "hsh.h"

/**
 * _isempty - look if str contains valid characters
 * @str: a string
 * @del: delimiters
 * Return: empty or not
**/

int _isempty(char *str, char *del)
{
	int i, j, empty;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; del[j] != '\0'; j++)
			{
				if (str[i] == del[j])
				{
					empty = 1;
					break;
				}
				else
				{
					empty = 0;
				}
			}
			if (empty == 0)
				return (empty);
		}
	}
	return (empty);
}

/**
 * _strtok1 - Tokenises a string given a set of delimiters. unlike the real
 * strtok doesn't deal with double separators and separators at the end and
 * start of the string...
 * @str: The string to be parsed.
 * @delims: A set of delimiters.
 *
 * Return: A pointer to a string token.
 *
 */

char *_strtok1(char *str, const char *delims)
{
	static char *strpt;
	char *token;

	if (_strlen(str) == 1 && isdel(str[0], delims))
		return (NULL);

	if (str)
		strpt = str;
	token = strpt;
	if (!token)
		return (NULL);

	while (*strpt)
	{
		if (isdel(*strpt, delims))
		{
			*strpt = '\0';
			strpt++;
			break;
		}
		strpt++;
	}

	if (*strpt == '\0')
		strpt = NULL;

	return (token);
}

/**
 * _strtok2 - Tokenises a string given a set of delimiters. works like the
 * real strtok.
 * @str: The string to be parsed.
 * @delims: A set of delimiters.
 *
 * Return: A pointer to a string token.
 *
 */

char *_strtok2(char *str, const char *delims)
{
	static char *strpt;
	static int charcount;
	char *token;

	if (_strlen(str) == 1 && isdel(str[0], delims))
		return (NULL);

	if (str)
	{
		strpt = str;
		charcount = 0;
	}
	token = strpt;
	if (!token)
		return (NULL);

	while (*strpt)
	{
		if (!isdel(*strpt, delims))
			charcount++;
		if (isdel(*strpt, delims) && charcount)
		{
			*strpt = '\0';
			if (!isdel(*(strpt + 1), delims))
			{
				strpt++;
				break;
			}
		}
		if (!charcount)
			token++;
		strpt++;
	}

	if (*strpt == '\0')
		strpt = NULL;

	return (token);
}

/**
 * _strdup - Creates a copy of a string and return a pointer to the first
 * character of the newly created string.
 * @str: The string to be copied
 *
 * Return: A copy of the string.
 *
 */

char *_strdup(char *str)
{
	char *str_cpy;
	int i;

	if (!str)
		return (NULL);

	str_cpy = malloc(sizeof(char *) * (_strlen(str) + 1));
	if (!str_cpy)
	{
		perror("Memory Allocation Error");
		return (NULL);
	}

	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
