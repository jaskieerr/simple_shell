#include "shell.h"

/**
 * exitin - Frees memory and exits the program.
 * @command: The array of strings to be freed.
 * @status: The exit status code.
 */
void exitin(char **command, int status)
{
	freestrsarr(command);
	exit(status);
}

/**
 * builtin_check - Checks if a command is a built-in command.
 * @command: The command to be checked.
 *
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int builtin_check(char *command)
{
	char *builts[] = {"exit", "cd", "env", "setenv", NULL};
	int i;

	for (i = 0; builts[i]; i++)
	{
		if (_strcmp(command, builts[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtin_hnd - Handles built-in commands.
 * @command: The array of command arguments.
 * @argv: An array of program arguments (not used).
 * @status: The exit status code.
 * @ind: An index (not used).
 */
void builtin_hnd(char **command, char **argv, int status, int ind)
{
	(void)ind;
	(void)argv;

	if (_strcmp(command[0], "exit") == 0)
		exitin(command, status);
	else if (_strcmp(command[0], "env") == 0)
		out_env(command, status);
}

/**
 * out_env - Prints environment variables to standard output.
 * @command: The array of command arguments (not used).
 * @status: The exit status code (not used).
 */
void out_env(char **command, int status)
{
	int i;
	(void)status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freestrsarr(command);
}

