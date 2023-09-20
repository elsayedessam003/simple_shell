#include "shell.h"
int _atoi(const char *str)
{
int i, sign;
unsigned int num;
i = 0;
sign = 1;
num = 0;
while (string[i] != '\0')
{
if (string[i] == '-')
sign *= -1;
else if (string[i] >= '0' && string[i] <= '9')
num = (num * 10) + (string[i] - '0');
else
break;
i++;
}
return (num *sign);
}
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
dest[i] = src[i];
return (dest);
}
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *p;
if (nmemb == 0 || size == 0)
return (NULL);
p = malloc(nmemb * size);
if (p == NULL)
return (NULL);
_memset(p, 0, nmemb * size);
return (p);
}
