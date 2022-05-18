#include "main.h"
/**
* errortime - prints error message, frees and exits child process
* @av: argument vector from main (used for av[0] filename)
* @cmds: cmd array made from strtokarray, used for first cmd
* @count: line count from loop
*/
void errortime(char **av, char **cmds, int count)
{
char *colon = ": ", *nf = "not found\n";
char *its = NULL;
int c = count, l = 0;

if (isatty(STDIN_FILENO))
{
write(STDERR_FILENO, cmds[0], _strlen(cmds[0]));
write(STDERR_FILENO, colon, 2);
write(STDERR_FILENO, "command not found\n", 18);
freeptrarray(cmds);
exit(EXIT_FAILURE);
}
write(STDERR_FILENO, av[0], _strlen(av[0]));
write(STDERR_FILENO, colon, 2);
while (c != 0)
{
c /= 10;
++l;
}
its = malloc(sizeof(char) * (l + 1));
if (its == NULL)
{
freeptrarray(cmds);
exit(EXIT_FAILURE);
}
its = _itoa(count, its, 10);
write(STDERR_FILENO, its, l);
write(STDERR_FILENO, colon, 2);
write(STDERR_FILENO, cmds[0], _strlen(cmds[0]));
write(STDERR_FILENO, colon, 2);
write(STDERR_FILENO, nf, 10);
free(its);
freeptrarray(cmds);
exit(EXIT_FAILURE);
}

/**
* _abs - printing absolute value of integer
* @a: character to check for value
* If a is greater than 0, return a.
*
* Else, multiply a by itself, then subtract itself once (to get positive)
* Return: prints absolute value of numbers
*/
int _abs(int a)
{

if (a >= 0)
return (a);

else
return (a - (a * 2));
}

/**
* _reverse - Reverses buffer[i..j]
* @buffer: buffer to be reversed
* @i: first spot to begin reversal
* @j: ending spot
* Return: pointer to reversed buffer
*/
char *_reverse(char *buffer, int i, int j)
{
while (i < j)
_swap(&buffer[i++], &buffer[j--]);
return (buffer);
}

/**
* _swap - Swaps two numbers
* @x: first number
* @y: second number
*/
void _swap(char *x, char *y)
{
char t = *x;
*x = *y;
*y = t;
}

/**
* _itoa - converts integer to string
* @value: value to be converted to a string.
* @buffer: array to store the resulting null-terminated string.
* @base: numerical base used to represent the value as a string
* between 2 & 36.
* Return: A pointer to the resulting null-terminated string, same as buffer
*/
char *_itoa(int value, char *buffer, int base)
{
int i = 0;
/* consider absolute value of number */
int n = _abs(value);
int r;

/* invalid input */
if (base < 2 || base > 32)
return (buffer);
while (n)
{
r = n % base;
if (r >= 10)
buffer[i++] = 65 + (r - 10);
else
buffer[i++] = 48 + r;
n = n / base;
}
/* if number is 0 */
if (i == 0)
buffer[i++] = '0';
/*
* If base is 10 & value is negative, the resulting string
* is preceded with a minus sign (-)
* With any other base, value is always considered unsigned
*/
if (value < 0 && base == 10)
buffer[i++] = '-';
buffer[i] = '\0'; /* terminator */
/* reverse the string & return it */
return (_reverse(buffer, 0, i - 1));

}
