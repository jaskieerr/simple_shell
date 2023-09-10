#include "shell.h"

/**
 * freestrsarr - free array.
 * @ary: str array to be freed.
 *
 *
 */
void freestrsarr(char **ary)
{
    int i;
    
    if (!ary)
        return;

    for (i = 0; ary[i]; i++)
    {
        free(ary[i]);
        ary[i] = NULL;
    }
    
    free(ary);
    ary = NULL;
}
