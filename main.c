#include "hsh.h"

int main(void)
{
	char **args;
	char *line;
	int status = 1;
	pid_t id;

	while (status)
	{
		display_prompt();
		line = hsh_readline();
		args = splitstr(line);
		hsh_exit(args[0]);
		id = fork();
		if (id == 0)
		{
			builtin(args[0]);
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
