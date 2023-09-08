#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;
int _execute(**command, char **argv);
char **tokenizer(char *line);
char *read_line(void);
char *_strdup(const char *str);


#endif