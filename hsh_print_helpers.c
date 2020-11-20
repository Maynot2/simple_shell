#include "hsh.h"

/**
 * _putchar - Prints a single character.
 * @c: A character.
 *
 * Return: 1 on success.
 *         0 if prints nothing.
 *        -1 on error.
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string follow by a newline.
 * @s: A string.
 *
 * Return: nb of printed char on success.
 *         0 if prints nothing.
 *        -1 on error.
 *
 */

int _puts(char *s)
{
	int count;
	char *str;

	str = _strcat(s, "\n");

	count = write(STDOUT_FILENO, str, _strlen(str));

	free(str);
	return (count);
}
