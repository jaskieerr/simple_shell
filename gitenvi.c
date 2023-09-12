#include "shell.h"

/**
 * _gitenvi - Get the value of an environment variable.
 * @varr: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if the variable is not found.
 */
char *_gitenvi(char *varr)
{
	char *val, *tmpp, *envv, *sar;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmpp = _strdup(environ[i]);
		sar = strtok(tmpp, "=");
		if (_strcmp(sar, varr) == 0)
		{
			val = strtok(NULL, "\n");
			envv = _strdup(val);
			free(tmpp);
			return (envv);
		}
		free(tmpp);
		tmpp = NULL;
	}
	return (NULL);
}
