#include "shell.h"

/**
 * validagetline - executes command lines entered by pipe
 * @buffer: program name
 * @len: length buffer
 * @args: Argument 1
 * @env_args: Enviroment arguments
 * Return: 0
*/
void validagetline(char *buffer, int len, char **args, char **env_args)
{
	if (len == EOF)
	{
		printf("EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buffer != NULL)
		{
			freedom(1, buffer);
			buffer = NULL;
		}
		if (args != NULL)
		{
			freedom(2, args);
			args = NULL;
		}
		if (env_args != NULL)
		{
			freedom(2, env_args);
			env_args = NULL;
		}
		exit(0);
	}
}

/**
 * execo - Executes a given command
 * @command: Given command
 * @args: command arguments
 * Return: Exit = 0 or Error Number
*/
int execo(char *command, char **args)
{
	int status;
	pid_t pid;
	int errcode = 0;

	pid = fork();
	if (!pid)
	{
		if (execve(command, args, environ) == -1)
		{
			freedom(1, command);
			command = NULL;
			errcode = errno;
			error_msg(args);
			exit(errcode);
		}
		else
		{
			freedom(1, command);
			command = NULL;
			exit(errcode);
		}
	}
	else
		wait(&status);

	freedom(1, command);
	command = NULL;
	errcode = 0;
	return (errcode);
}

/**
**find_builtins -  finds wheter user's command is a builtin
** @user_input: user's command
**Return: pointer to function builtin or NULL if doesn't exists
**/
int (*find_builtins(char *user_input))()
{
	int counter = 0, stru_size = 0;

	builtin_struct our_builtins[] = {
		{"exit", exit_func},
		{"env", env_func},
	};

	stru_size = (sizeof(our_builtins) / sizeof(builtin_struct));
	if (user_input != NULL)
	{
		while (counter < stru_size)
		{
			if (strcomp(our_builtins[counter].b_name, user_input) == 0)
				return (our_builtins[counter].b_func);
			counter++;
		}
	}
	return (NULL);
}

/**
 * notty - executes command lines entered by pipe
 * @av: program name
 * Return: 0
*/
int notty(char **av __attribute__((unused)))
{
	size_t bufsize;
	int len = 0;
	char *buffer = NULL;
	char **env_args = NULL;
	char **user_command = NULL;
	char *full_command = NULL;
	int (*b_func)() = NULL;

	while ((len = getline(&buffer, &bufsize, stdin)) > 0)
	{
		validagetline(buffer, len, user_command, env_args);
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		user_command = args_constructor(buffer);
		if (user_command == NULL)
			continue;
		b_func = find_builtins(*user_command);
		if (b_func)
		{
			if (b_func == exit_func)
				free_all(user_command, env_args, buffer, NULL);
			b_func();
			free_all(user_command, NULL, NULL, NULL);
			continue;
		}
		env_args = getenvpath();
		if (env_args == NULL)
			return (-1);
		full_command = _include_path(user_command, env_args);
		if (full_command == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execo(full_command, user_command);
		freedom(1, buffer), buffer = NULL;
		freedom(2, user_command), user_command = NULL;
		freedom(2, env_args), env_args  = NULL;
	}
	freedom(1, buffer), buffer = NULL;
	return (0);
}

/**
 * exit_func - Builtin function that exits from shell
 * Return: 0
*/
int exit_func(void)
{
	exit(0);
}
