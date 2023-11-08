#include "shell.h"

/**
 * print_error - Displays existing error message
 * @input: Input recieved from user
 * @counter: count of shell loop
 * @argv: Arguments before program starts
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT("; ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 * _prerror - prints custom error
 * @argv: Arguments before program starts
 * @c: error count
 * @cmd: array of parsed command strings
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * error_file - prints custom error
 * @argv: Arguments before program starts
 * @c: Error count
 */

void error_file(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}

