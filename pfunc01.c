#include "shell.h"

/**
 * init_shell - function to initialize the shell program
 */
void init_shell(void)
{
	clear();
	printf("\n\n***********************************************");
	printf("\n\n****SIMPLE SHELL BY DSOFT02 & MANLIKETEETOS****");
	printf("\n\n***********************************************");
	printf("\n");
	sleep(1);
	clear();
}

/**
 * prompt - function that write a prompt
 *
 * Return: 0 on sucess
 */
int prompt(void)
{
	char *prompt = "$ ";
	ssize_t linecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		linecount = write(STDOUT_FILENO, prompt, 2);
		if (linecount == -1)
			exit(0);
	}
	return (0);
}

/**
 * _read - reads stdin and stores it in a buffer
 *
 * Return: a pointer to the buffer
 */
char *_read(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
