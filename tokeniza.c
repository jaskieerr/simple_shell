#include "shell.h"
/*here 
goe cmnts*/
char **tokenizer(char *line)
{
    char *token = NULL, *tmpp = NULL;
    char **command = NULL;
    int count =0, i = 0;

    if (!line)
        return(NULL);
    tmpp = _strdup(line);

    token = strtok(tmpp,DELIM);
    if (token == NULL)
    {   free(line); line = NULL;
        free(tmpp); tmpp = NULL;
        return(NULL); 
    }
    while (token)
    {
        count++;
        token = strtok(NULL, DELIM);
    }
    free(tmpp); tmpp = NULL;

    command = malloc(sizeof(char *) *(count + 1));
    if (!command)
    {
        free(line);
        return (NULL);
    }

    token = strtok(line,DELIM);
    while (token)
    {
        command [i++] = token;
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line); line =NULL;
    command[i] = NULL;
    return(command);
}