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
    char *line = NULL;
    char **command = NULL;
    int status = 0;

    (void)ac;
    (void)argv;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }

        command = tokenizer(line);
        if (!command)
            continue;

        status = _execute(command, argv);
    }

    return (0);
}
