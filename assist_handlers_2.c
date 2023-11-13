#include "shell.h"

/**
 * assist_env - Displays information on the shellby builtin command 'env'
 */
void assist_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * assist_setenv - Displays information on the shellby builtin command 'setenv'
 */
void assist_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * assist_unsetenv - Displays information on the shellby builtin command
 *                   'unsetenv'
 */
void assist_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemonves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help - display help for builtin commands
 * @cmd: parsed command
 * @st: status of last command executed
 *
 * Return: 0 success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		assist_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		assist_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		assist_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		assist_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		assist_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		assist_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		assist_unsetenv();
	else if (_strcmp(cmd[1], "help") == 0)
		assist_env();
	return (0);
}

