#include "shell.h"
int _strlength(const char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
int _strcmp(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}
return ((int)(*s1)-(*s2));
}
int _strncmp(const char *s1, const char *s2, size_t n)
{
unsigned char c1, c2;
while (n-- > 0)
{
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 != c2)
return (c1 - c2);
if (c1 == '\0')
break;
}
return (0);
}
char *_strstr(char *haystack, char *needle)
{
int i;
for (i = 0; haystack[i] != '\0'; i++)
{
if (haystack[i] == needle[0])
{
int j;
for (j = 0; needle[j] != '\0'; j++)
{
if (haystack[i + j] != needle[j])
{
break;
}
}
if (needle[j] == '\0')
{
return (&haystack[i]);
}
}
}
return (NULL);
}
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}
if (*s == c)
return (s);
return (NULL);
}
