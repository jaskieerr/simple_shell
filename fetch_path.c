#include "shell.h"

/**
 * _fetchpath - Find the full path to an executable command.
 * @command: The name of the command.
 *
 * Return: A dynamically allocated string containing the full path or NULL if not found.
 */
char *_fetchpath(char *command)
{
    int i;
    char *pathev, *fullcom, *directory;
    struct stat stt;


    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &stt) == 0)
            {
                
                return (_strdup(command));
            }
            return (NULL);
        }
    }

    pathev = _gitenvi("PATH");
    if (!pathev)
    {
        return (NULL);
    }

    directory = strtok(pathev, ":");
    while (directory)
    {
        fullcom = malloc(_strlen(directory) + _strlen(command) + 2);
        if (fullcom)
        {
            _strcpy(fullcom, directory);
            _strcat(fullcom, "/");
            _strcat(fullcom, command);
            if (stat(fullcom, &stt) == 0)
            {
                free(pathev); 
                return (fullcom);
            }

            free(fullcom);
            directory = strtok(NULL, ":");
        }
    }

    free(pathev); 
    return (NULL);
}
