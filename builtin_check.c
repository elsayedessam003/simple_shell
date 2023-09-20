#include "shell.h"


int check_for_builtin(char **argus)
{
	if (!argus[0])
		return (0);
	if (!_strcmp(argus[0], "exit"))
		shell_exit(argus);
	else if (!_strcmp(argus[0], "environment"))
		shell_env();
	else if (!_strcmp(argus[0], "setenvironment"))
		shell_setenv(argus);
	else if (!_strcmp(argus[0], "unsetenvironment"))
		shell_unsetenv(argus);
	else if (!_strcmp(argus[0], "help"))
		shell_help();
	else if (!_strcmp(argus[0], "change_d"))
		shell_cd(argus);
	else if (!_strcmp(argus[0], "clear"))
		shell_clear(argus);
	else
		return (0);
	return (1);
}
