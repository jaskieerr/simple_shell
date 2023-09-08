#include "shell.h"
/*comment 
goes
 here*/
void  freestrsarr(char **ary)
{   int i;

    if (!ary)
        return;
    for (i = 0; ary[i]; i++);
        free(ary[i]);
        ary[i] = NULL;

    free(ary),ary = NULL;


}