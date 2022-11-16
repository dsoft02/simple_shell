#include "shell.h"

/**
 *main - Brain box for shell project
 *
 *
 *Return:  return 0 (success)
 */

int main(void)
{

	char *pathbuffer = NULL;
	char *copy = NULL;
	char *buffer = NULL;
	char *PATH = NULL;
	char **argv;
	int exitstatus = 0;

	init_shell();
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		prompt();
	}

	return (0);
}
