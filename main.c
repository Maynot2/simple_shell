#include "hsh.h"

int main(void)
{
	char **args;
	char *line;
	pid_t id;

	while (1)
	{
		id = fork();
		if (id == 0)
		{
			display_prompt();
			line = hsh_readline();
			args = splitstr(line);
			hsh_exec_cmd(args);
			free(line);
			free(args);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
