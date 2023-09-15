#include "shell.h"
void handle_signit(int sig)
{
(void) sig;
_putchar('\n');
prompt();
}
void handle_sigquit(int sig)
{
(void) sig;
_puterror("Quit (core dumped)\n");
exit(EXIT_SUCCESS);
}
void handle_sigstp(int sig)
{
(void) sig;
_puts("\n");
prompt();
}
