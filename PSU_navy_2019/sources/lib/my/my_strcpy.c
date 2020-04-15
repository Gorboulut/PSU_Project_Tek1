/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** my_strcpy.c
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 2);
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
