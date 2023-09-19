#include "shell.h"
/**
 * _execute - Executes a given command.
 * @command: str arr of the cmd and its arguments.
 * @argv: str arr of args passed to the shell.
 * @ind: Index of the command.
 *
 * Return: 0 if success, -1 if not.
 */
int _execute(char **command, char **argv, int ind)
{
	char *fullcom;
	pid_t child;
	int status;

	fullcom = _fetchpath(command[0]);
	if (!fullcom)
	{
		out_error(argv[0], command[0], ind);
		freestrsarr(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(fullcom, command, environ) == -1)
		{
			free(fullcom);
			fullcom = NULL;
			freestrsarr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freestrsarr(command);
		free(fullcom);
		fullcom = NULL;
	}
	return (WEXITSTATUS(status));
}