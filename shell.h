#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

extern char **environ;

#define clear() printf("\033[H\033[J")

void init_shell(void);
int prompt(void);
char *_read(void);


/* basic functions */
int _putchar(char c);
void _puts(char *str);


/* string functions */
int _strcomp(const char *s1, const char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _countstring(char *str);
char *_strdup(char *str);
int _splitstring(char *str);

/* Path functions */
char *_pathbuffer(char **av, char *PATH, char *copy);
int _splitPath(char *str);
int _strcmpPath(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tok);

/* program logic */

int checkbuiltins(char **av, char *buffer, int exitstatus);
int _forkprocess(char **av, char *buffer, char *pathbuffer);

#endif
