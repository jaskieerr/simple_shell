#include "shell.h"

/**
 * main - shell entry point.
 * @ac: arg count.
 * @argv: argv as usual.
 *
 * Return: Always returns 0.
 */
int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, ind = 0;

	(void)ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		ind++;
		command = tokenizer(line);
		if (!command)
			continue;

		if(builtin_check(command[0]))
			builtin_hnd(command, argv, status, ind);
		else	
		status = _execute(command, argv, ind);
	}

}
