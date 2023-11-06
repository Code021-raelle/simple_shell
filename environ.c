#include "shell.h"


/**
 * create_environ - Creates an array of environment variables
 * @environ: Array to store enviroment variables
 */
void create_environ(char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
		environ[i] = _strdup(environ[i]);
	environ[i] = NULL;
}


/**
 * free_env - frees the memory of the created environment variables array
 * @env: Array of environment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}

