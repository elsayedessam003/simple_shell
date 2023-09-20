#include "shell.h"


void free_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}


void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}



void free_path(void)
{
	if (env != NULL)
	{
		size_t i = 0;

		while (env[i] != NULL)
		{
			if (_strncmp(env[i], "PATH=", 5) == 0)
			{
				free(env[i]);
				env[i] = NULL;
				break;
			}
			i++;
		}
	}
}
