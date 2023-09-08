#include "shell.h"
/**
 * here
 * goes
 * comments
*/

int _execute(char**command, char **argv)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        if(execve(command[0],command,environ) == -1)
        {
            perror(argv[0]);
            freestrsarr(command);
            exit(0);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freestrsarr(command);
    }
    return(WEXITSTATUS(status))
}   