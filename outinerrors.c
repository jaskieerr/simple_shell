#include "shell.h"

/**
 * out_error - Prints error to stdo
 * @nombre: nobre del program amigo.
 * @command: achilles heel.
 * @ind: achilles heel's index.
 *
 * Description: prints error to output simply
 */
void out_error(char *nombre, char *command, int ind)
{
	char *indexu, message[] = ": not found\n";

	indexu = _itoa(ind);

	write(STDERR_FILENO, nombre, _strlen(nombre));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indexu, _strlen(indexu));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));
	free(indexu);
}

/**
 * _itoa - converts int to str
 * @n: The integer to be converted.
 * Return: result str poiter
 *
 * Description: This function converts an int to a str.
 * and returns the return read it.
 */
char *_itoa(int n)
{
	char buffea[20];
	int i = 0;

	if (n == 0)
		buffea[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffea[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffea[i] = '\0';
	rev_str(buffea, i);
	return (_strdup(buffea));
}

/**
 * rev_str - revs an str
 * @str: str to be reversed.
 * @len: len of the str.
 *
 * Description: This function reverses a string in-place.
 */
void rev_str(char *str, int len)
{
	char tmpp;
	int startu = 0;
	int endu = len - 1;

	while (startu < endu)
	{
		tmpp = str[startu];
		str[startu] = str[endu];
		str[endu] = tmpp;
		startu++;
		endu--;
	}
}

