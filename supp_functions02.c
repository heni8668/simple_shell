#include "main.h"
/**
* _getenv - function
* @name: name of variable
*
* Description: function to get environment variable
* Return: char variable or NULL if empty
*/
char *_getenv(const char *name)
{
char **ep = environ;
char *np;
int a, b;

a = b = 0;
while (ep[a] != NULL)
{
b = 0;
np = ep[a];
while (np[b] != '=')
b++;
if (_strncmp(np, name, b) == 0)
{
while (b > 0)
{
np++;
b--;
}
return (++np);

}
a++;
}
return (NULL);
}
/**
* strtokarray - creates an array of pointers to tokens from input string
* @str: input string
* Return: the double pointer, or NULL
*/
char **strtokarray(char *str)
{
char **tokarray;
char *tok;
int c, len, t;

c = len = t = 0;
while (str[c] != '\0')
{
if (str[c + 1] == ' ' || str[c + 1] == '\0')
t++;
c++;
}
if (c == 0)
return (NULL);
str[_strlen(str) - 1] = '\0';
tokarray = malloc(sizeof(char *) * (t + 1));
if (tokarray == NULL)
{
free(tokarray);
return (NULL);
}
tok = strtok(str, " ");
c = 0;
while (tok != NULL)
{
len = _strlen(tok);
tokarray[c] = malloc(len + 1);
if (tokarray[c] == NULL)
{
freeptrarray(tokarray);
return (NULL);
}
_strncpy(tokarray[c], tok, len + 1);
tok = strtok(NULL, " ");
c++;
}
tokarray[c] = NULL;
return (tokarray);
}
/**
* execute_input - Executes command via child process
* @av: argument vector from main, used for program name at av[0]
* @cmds: strtok array of directories from PATH
* @env: environment from main. Used for execve
* @count: line count for shell
* Return: Always 0 after child completes
*/
int execute_input(char **av, char **cmds, char **env, int count)
{
int status;
struct stat sstat;
pid_t child;
char *str = NULL;

child = fork();
if (child == -1)/* Fork failed */
{
perror("./hsh");
exit(EXIT_FAILURE);
}
else if (child == 0)/* I am the child! */
{
if (stat(cmds[0], &sstat) == 0)
execve(cmds[0], cmds, env);
else
{
str = pathandfree(cmds[0]);
if (str == NULL)
errortime(av, cmds, count);
else
execve(str, cmds, env);
}
}
else/* pid above 0, so thats ppid. wait until child ends */
{
waitpid(child, &status, WUNTRACED);
freeptrarray(cmds);
/*free(str);*/
}
return (status);
}
/**
* freeptrarray - frees all pointers from the array
* @ptr: pointer to pointer array
*/
void freeptrarray(char **ptr)
{
int c = 0;

while (ptr[c] != NULL)
c++;

while (c >= 0)
{
free(ptr[c]);
c--;
}
free(ptr);
}
/**
* _strcmp - function
* @s1: comparing string
* @s2: comparing string
*
* Description: compare str1 to str2
* Return: str1, str2
*/
int _strcmp(char *s1, char *s2)
{
int len;

for (len = 0; s1[len] && s2[len];)
{
if (s1[len] == s2[len])
len++;
else
break;
}
return (s1[len] - s2[len]);
}
