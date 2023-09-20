#include "shell.h"


void shell_help(void)
{
	_puts("\nShell Version 1.0.0\n\n");
	_puts("Usage: ./hsh\n\n");
	_puts("Shell built-in commands:\n\n");
	_puts("help\t\tDisplay help information\n\n");
	_puts("cd [dir]\tChange this working directory\n\n");
	_puts("env\t\tDisplay environment variables\n\n");
	_puts("setenv\t\tSet an environment variable\n\n");
	_puts("unsetenv\tUnset an environment variable\n\n");
	_puts("exit\t\tExit shell\n\n");
}
