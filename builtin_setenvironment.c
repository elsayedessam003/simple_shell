#include "shell.h"


int shell_setenvirnoment(char **argus)
{
	char *name, *value;

	if (argus[1] == NULL || argus[2] == NULL)
	{
		_puterror("Usage: Set environment VARIABLE VALUE\n");
		return (-1);
	}

	name = argus[1];
	value = argus[2];

	if (setenvironment(name, value, 1) != 0)
	{
		_puterror("Set environment");
		return (-1);
	}
	return (0);
}


int shell_unsetenvironment(char **argus)
{
	char *name;

	if (argus[1] == NULL)
	{
		_puterror("Usage: Unset environment VARIABLE\n");
		return (-1);
	}

	name = argus[1];

	if (unsetenv(name) != 0)
	{
		_puterror("Unset environment");
	}
	return (0);
}
