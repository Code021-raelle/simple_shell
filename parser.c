#include "shell.h"

/**
 * parse_cmd - parses the command recieved from stdin
 * @input: string gathered
 *
 * Return: parsed strings to be used as arguments
 */

char **parse_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = my_strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = my_strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}

