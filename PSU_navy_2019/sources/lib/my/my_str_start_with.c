/*
** EPITECH PROJECT, 2020
** my_str_start_with.c
** File description:
** my_str_start_with.c
*/

#include "my.h"

int my_str_start_with(char *str, char *str2)
{
    int i;

    for (i = 0; str[i] && str2[i]; i++)
        if (str[i] != str2[i])
            return (0);
    if (str2[i] == 0)
        return (1);
    return (0);
}
