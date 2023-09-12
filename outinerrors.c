#include "shell.h"

/**
 * here
 * goes comments
*/
void out_error(char *nombre, char *command, int ind)
{
    char *indexu, message[] = ": not found\n";

    indexu = _itoa(ind);

    write(STDERR_FILENO,nombre,_strlen(nombre));
    write(STDERR_FILENO,": ",2);
    write(STDERR_FILENO,indexu, _strlen(indexu));
    write(STDERR_FILENO,": ", 2);
    write(STDERR_FILENO, command, _strlen(command));
    write(STDERR_FILENO, message, _strlen(message));
    free(indexu); 
}

/**
 * coment 
 * go here
*/
char *_itoa(int n)
{
    char buffea[20];
    int i = 0;
    
    if( n == 0)
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
        return(_strdup(buffea));
}
void rev_str(char *str, int len)
{
    char tmpp;
    int startu = 0; int endu = len -1;

    while (startu < endu)
    {
        tmpp = str[startu];
        str[startu] = str[endu];
        str[endu] = tmpp;
        startu++;
        endu--;
    }

}