#include "shell.h"
static char *last_input;
/**
* get_input - read the line of input from user.
*
* return: pointer to a buffer containing the user's input.
*/
char *get_input(void)
{
char *input = NULL;
size_t input_size = 0;
ssize_t nread;
do {
prompt();
nread = getline(&input, &input_size, stdin);
if (nread == -1)
{
free(input);
_puts("\n");
return (NULL);
}
input[nread - 1] = '\0';
} while (input[0] == '\0' || isspace(input[0]));
last_input = input;
return (input);
}
void free_last_input(void)
{
free(last_input);
last_input = NULL;
}
