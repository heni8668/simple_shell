#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
void _printppid(void);
int _putchar(char c);
char *read_input(void);
char **strtokarray(char *str);
void freeptrarray(char **ptr);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *str_concat(char *s1, char *s2);
int execute_input(char **av, char **cmds, char **env, int count);
char *_getenv(const char *name);
extern char **environ;
/**
 * struct pathlist - nodes for singly linked list of PATH directories
 * @str: single directory from PATH
 * @next: pointer to next node in list
 */
typedef struct pathlist
{
	char *str;
	struct pathlist *next;
} list_p;
list_p *add_node(list_p **head, char *str);
list_p *createpathlist(char *str);
size_t print_list(const list_p *h);
void free_list(list_p *head);
list_p *pathlist(void);
void env_print(char **env);
char *pathandfree(char *arg);
char *pathchecker(list_p **head, char *arg);
int spacecheck(char *line);
void _halt(int sig);
void freeptrarrayandexit(char **str, int stat);
int _strcmp(char *s1, char *s2);
void errortime(char **av, char **cmds, int count);
char *_itoa(int value, char *buffer, int base);
int _abs(int a);
char *_reverse(char *buffer, int i, int j);
void _swap(char *x, char *y);
int _atoi(char *str);
#endif /*MAIN_H*/
