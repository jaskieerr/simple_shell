#include "shell.h"

/**
 * read_line - Reads string from the stdin
 *
 * Return: A ptr to allocated str containing the line
 *         NULL if shiitt went south
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
