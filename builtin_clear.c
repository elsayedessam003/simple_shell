#include "shell.h"


int shell_clear(char **argus)
{
	(void)argus;
	_puts("\033[2J\033[H");
	return (1);
}
