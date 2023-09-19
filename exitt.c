#include "shell.h"

void exitin(char **command, int status)
{
    freestrsarr(command);
    exit(status);
}

int builtin_check(char *command)
{
    char *builts [] = {"exit", "cd","env","setenv", NULL};
    int i;
    
    for(i = 0;builts[i]; i++ )
    {
        if(_strcmp(command, builts[i]) == 0)
            return(1);
    }
    return(0);
}

void builtin_hnd(char **command,char **argv,int status,int ind)
{
    (void) ind;
    (void) argv;

    if(_strcmp(command[0], "exit") == 0)
        exitin(command, status);
    else if (_strcmp(command[0],"env") == 0)
        out_env(command, status);
}
void out_env(char **command, int status)
{
    int i;
    (void) status;
    
    for(i = 0;environ[i];i++)
    {
        write(STDOUT_FILENO,environ[i],_strlen(environ[i]));
        write(STDOUT_FILENO,"\n",1);
    }
    freestrsarr(command);

}   
