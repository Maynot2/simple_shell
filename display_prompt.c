#include "hsh.c"

/**
 * display_prompt - display a prompt
 * Return: nothing
 **/

void display_prompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 3) == -1) // display prompt
		perror("Write Error\n");
}
