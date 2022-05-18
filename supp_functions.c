#include "main.h"
/**
* _strncpy - function
* @dest: copy to string
* @src: copy from string
* @n: at parameter
*
* Description: copies a string to the nth value.
* Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
int len;

for (len = 0; src[len]; len++)
{
if (n > len)
dest[len] = src[len];
}
for ( ; n > len; len++)
{
dest[len] = '\0';
}
return (dest);
}
/**
* _strlen - function
* @s: first operand & pointer
*
* Description: function that returns the length of a string
* Return: Always 0
*/
int _strlen(char *s)
{
int index = 0;

while (*s != '\0')
{
index++;
s++;
}
return (index);
}
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* _strncmp - function
* @s1: string to compare to
* @s2: string to compare
* @n: # of characters to compare to s1
*
* Description: function to compare to strings up to the nth character
* Return: 0 Success
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
while (n--)
{
if (*s1++ != *s2++)
return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
}
return (0);
}

/**
* str_concat - function
* @s1: string to add to
* @s2: string to add
*
* Description: functions to concat two strings
* Return: string
*/
char *str_concat(char *s1, char *s2)
{
char *cpy = NULL;
int t, a, b;
char *s1c = NULL, *s2c = NULL;

s1c = s1;
s2c = s2;
if (s1c == NULL)
{
s1c = malloc(1);
*s1c = '\0';
}
if (s2c == NULL)
{
s2c = malloc(1);
*s2c = '\0';
}
t = _strlen(s1c);
t += _strlen(s2c);
t += 1;
cpy = malloc(sizeof(char) * t);
if (cpy == NULL)
return (NULL);
for (a = 0; s1c[a] != '\0'; a++)
cpy[a] = s1c[a];
for (b = 0; a != t && s2c[b] != '\0'; b++, a++)
{
cpy[a] = s2c[b];
}
cpy[a] = '\0';
return (cpy);
}
