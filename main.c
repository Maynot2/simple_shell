#include "hsh.h"

int main(void)
{
	char **args;
	char *line;
	int status = 1;
	pid_t id;

	while (status)
	{
		id = fork();
		if (id == 0)
		{
			display_prompt();
			line = hsh_readline();
			args = splitstr(line);
			status = hsh_exec_cmd(args);
			free(line);
			free(args);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
