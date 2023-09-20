#include "shell.h"


void shell_exit(char **argus)
{
	int status = 0;

	if (argus[1] != NULL)
	{
		status = _atoi(argus[1]);
	}
	free_tokens(argus);
	free_last_input();
	exit(status);
}
