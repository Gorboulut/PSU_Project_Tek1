/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i;
    int j;

    str = malloc(sizeof(char) * (j + 1));
    for (int i = 0; i < j;){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
