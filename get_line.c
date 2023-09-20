#include "shell.h"


void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_position, buf_size;
	char *input_string = NULL;
	char current_char;
	int input_length = 0;

	while (1)
	{
		if (buf_position >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_position = 0;
			if (buf_size == 0)
				return (input_string);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_position];

		buf_position++;

		if (current_char == '\n')
		{
			input_string = realloc(input_string, input_length + 1);
			input_string[input_length] = '\0';
			return (input_string);
		}
		else
		{
			input_string = realloc(input_string, input_length + 1);
			input_string[input_length] = current_char;
			input_length++;
		}
	}
}
