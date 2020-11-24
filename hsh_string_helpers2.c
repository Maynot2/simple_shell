#include "hsh.h"

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
