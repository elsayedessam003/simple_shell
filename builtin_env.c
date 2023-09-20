#include "shell.h"


int shell_environment(void)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		_puts(env[i]);
		_putchar('\n');
	}

	return (0);
}
