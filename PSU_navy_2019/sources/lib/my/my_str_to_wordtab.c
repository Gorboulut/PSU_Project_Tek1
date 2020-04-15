/*
** EPITECH PROJECT, 2020
** my_str_to_wordtab.c
** File description:
** my_str_to_wordtab.c
*/

#include "my.h"

static int nb_lines(char const *str, char c)
{
    int i;
    int nb;

    for (i = 0; str[i]; i++)
        if (str[i] == c && str[i + 1])
            nb++;
    return (nb);
}

static int conditions(char c, char condition)
{
    if (c)
        if (c != condition)
            return (1);
    return (0);
}

char **my_str_to_wordtab(char *str, char c)
{
    char **res = NULL;
    int y = 0;
    int i = 0;

    res = malloc(sizeof(char *) * 13);
    for (int x = 0; str[x];) {
        for (y = 0; conditions(str[x + y], c); y++);
        if (y != 0) {
            res[i] = malloc(sizeof(char) * (y + 1));
            my_strncpy(res[i], str + x, y);
            res[i][y] = '\0';
            i++;
            x += y;
        }
        if (str[x])
            x++;
    }
    res[i] = NULL;
    return (res);
}
