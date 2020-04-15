/*
** EPITECH PROJECT, 2019
** my_strcat_2.c
** File description:
** my_strcat_2.c
*/

#include "my.h"

int my_strlen(char const *str);

char *my_strcat2(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i;
    char *tabl = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));

    for (i = 0; dest[i] != '\0'; i++)
        tabl[i] = dest[i];
    for (i = 0; src[i] != '\0';) {
        tabl[length] = '=';
        tabl[i + length + 1] = src[i];
        i++;
    }
    tabl[length + i + 1] = '\0';
    return (tabl);
}
