#include "shell.h"
/**
 * coment 
 * go
 * here
*/
char *_gitenvi(char *varr)
{
    char *val, *tmpp, *envv, *sar;
    int i;

    for ( i = 0; environ[i]; i++)
    {
        tmpp = _strdup(environ[i]);
        sar = strtok(tmpp, "=");
        if(_strcmp(sar, varr) == 0)
        {
            val = strtok(NULL,"\n");
            envv = _strdup(val);
            free(tmpp);
            return (envv);
        }
        free(tmpp),tmpp = NULL;
    }
    return (NULL);
}
