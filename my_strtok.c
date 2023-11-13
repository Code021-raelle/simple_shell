#include "shell.h"

/**
 * pass_delim - function that pass or checks if a character
 *              matches any character
 * @c: character to chack
 * @str: string of delimeters
 *
 * Return: 1 if success, 0 if failure.
 */

unsigned int pass_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * my_strtok - function that extracts tokens of a string
 * @str: string
 * @delim: delimeter
 *
 * Return: pointer to the next token or NULL.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *fresh_token;
	unsigned int i;

	if (str != NULL)
		fresh_token = str;
	tokens = fresh_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (pass_delim(tokens[i], delim) == 0)
			break;
	}
	if (fresh_token[i] == '\0' || fresh_token[i] == '#')
	{
		fresh_token = NULL;
		return (NULL);
	}
	tokens = fresh_token + i;
	fresh_token = tokens;
	for (i = 0; fresh_token[i] != '\0'; i++)
	{
		if (pass_delim(fresh_token[i], delim) == 1)
			break;
	}
	if (fresh_token[i] == '\0')
		fresh_token = NULL;
	else
	{
		fresh_token[i] = '\0';
		fresh_token = fresh_token + i + 1;
		if (*fresh_token == '\0')
			fresh_token = NULL;
	}
	return (tokens);
}

