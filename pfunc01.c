#include "shell.h"

/**
 * init_shell - function to initialize the shell program
*/
void init_shell()
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