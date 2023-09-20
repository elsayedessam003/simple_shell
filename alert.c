#include "shell.h"


void _puts(char *string)
{
	size_t length;
	ssize_t num_written;

	length = _strlength(string);
	num_written = write(STDOUT_FILENO, string, length);
	if (num_written == -1)
	{
		perror("write");
	}
}


void _puterror(char *err)
{
	size_t length;
	ssize_t num_written;

	length = _strlength(err);
	num_written = write(STDERR_FILENO, err, length);
	if (num_written == -1)
	{
		perror("write");
	}
}
