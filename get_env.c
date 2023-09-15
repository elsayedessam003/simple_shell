#include "shell.h"
/**
* _getenv - get the value of an environment variable
* @name: name of the environment variable
*
* return: value of the environment variable, or null if it doesnot exist
*/
char *_getenv(const char *name)
{
char **env;
size_t name_len = _strlen(name);
for (env = environment; *env != NULL; env++)
{
if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
{
return (&(*env)[name_len + 1]);
}
}
return (NULL);
}
