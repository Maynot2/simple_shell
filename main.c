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
		if (line == NULL)
		{
			printf("OK");
			return (1);
		}
		id = fork();
		if (id == 0)
		{
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
