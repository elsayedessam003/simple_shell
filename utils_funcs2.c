#include "shell.h"
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
char *_strcat(char *dest, const char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}
int _putchar(char c)
{
return (write(1, &c, 1));
}
unsigned int _strspn(char *s, char *accept)
{
unsigned int i, j;
for (i = 0; s[i]; i++)
{
for (j = 0; accept[j]; j++)
{
if (s[i] == accept[j])
break;
}
if (!accept[j])
return (i);
}
return (i);
}
