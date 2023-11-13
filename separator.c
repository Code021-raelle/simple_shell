#include "shell.h"

/**
 * separator - Separates command recieved from stdin by ;
 *
 * @input: string gathered from stdin
 *
 * Return: parsed strings to be used as commands
 */

char **separator(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}

	command = my_strtok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = my_strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}

