#include "hsh.h"

/**
 * display_prompt - display a prompt
 * Return: nothing
 **/

void display_prompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 2) == -1)
		perror("Write Error\n");
}
