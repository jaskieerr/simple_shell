#include "shell.h"

/**
 * _strdup - a function that Duplicate a string.
 * @str: string to duplicate.
 *
 * Return: ptr to the duplicated string, NULL allocation failed.
 */
char *_strdup(const char *str)
{
    char *ptr;
    int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    ptr = malloc(sizeof(char) * (len + 1));

    if (ptr == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        ptr[i] = str[i];

    return (ptr);
}

/**
 * _strcmp - Compare two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: eehhh ,kinda depends.
 */
int _strcmp(char *s1, char *s2)
{
    int cmp;

    cmp = (int)*s1 - (int)*s2;

    while (*s1)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }

    return (cmp);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: str to be calculated
 *
 * Return: string length.
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return (len);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: destination string ptr.
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    while (*ptr)
        ptr++;

    while (*src)
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = *src;

    return (dest);
}
