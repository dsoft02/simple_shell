#include "shell.h"
/**
 * main - Shell entry point
 * @argc: Argument counter
 * @argv: Argument values
 * Return: Exit if success = 0
*/

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{

	int int_mode = 1;
	int errcode = 0;

	loop = 1;
	shell_home = argv[0];
	errcode = errcode + 0;

	int_mode = isatty(STDIN_FILENO);
	if (int_mode == 0)
	{
		notty(argv);
	}
	else
	{

		_interactive(argv);
	}
	return (0);
}
