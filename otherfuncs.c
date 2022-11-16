#include "shell.h"

/**
 * countCommands - counts commands and options entered by user
 * @buffer: given command
 * Return: Number of arguments
*/
int countCommands(char *buffer)
{
	int pearls = 0;
	char *delimiter = " =:'\n''\t'";
	int i = 0;
	int j = 0;

	while (buffer[i] != '\0')
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (buffer[i] == delimiter[j])
			{
				pearls++;
				break;
			}
		}
		i++;
	}
	return (pearls + 1);
}

/**
 * parsing - Function that splits a given string
 * @buffer: Given string
 * @characters: number of elements
 * Return: Tokenized string
*/

char **parsing(char *buffer, int characters)
{
	int counter = 0;
	char *token = NULL;
	char *delimiter = " :'\n''\t'";
	char **token_necklace = malloc(sizeof(char *) * characters);

	if (token_necklace == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		token_necklace[counter] = strduplicate(token);
		if (token_necklace[counter] == NULL)
		{
			freedom(2, token_necklace);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		counter++;
	}
	token_necklace[counter] = NULL;
	return (token_necklace);
}

/**
 * error_msg - writes error depending on the error number
 * @args: given command to execute
 * Return: Nothing
*/
void error_msg(char **args)
{
	char *error_message = malloc(sizeof(char) * 255);
	char *looper = NULL;

	looper = int_to_char(loop);
	error_message = strduplicate(shell_home);
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, looper);
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, args[0]);
	perror(error_message);
	free(error_message);
}

/**
 * error_badcommand - writes error depending on the error number
 * @args: given command to execute
 * @buffer: given command to execute
 * Return: Nothing
*/
void error_badcommand(char **args, char *buffer)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	freedom(1, buffer);
	buffer = NULL;
	freedom(2, args);
	args = NULL;
}
