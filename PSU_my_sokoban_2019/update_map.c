/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban game
*/
#include <ncurses.h>
#include <stdlib.h>
#include "include/my.h"
#include <sys/stat.h>
#include <stdarg.h>
#include <fcntl.h>

int get_top_lign(char *map)
{
    int i = 0;
    int x = 0;

    while (map[i] != 'P')
        i++;
    while (map[i] != '\n' && i > 1)
        i--;
    i--;
    while (map[i] != '\n' && i > 0) {
        x++;
        i--;
    }
    x++;
    return (x);
}

int get_lign(char *map)
{
    int i = 0;
    int x = 0;

    while (map[i] != 'P')
        i++;
    while (map[i] != '\n')
        i--;
    i++;
    while (map[i] != '\n') {
        x++;
        i++;
    }
    x++;
    return (x);
}

int get_x_top(char *map)
{
    int i = 0;
    int x = 0;

    while (map[i] != 'P')
        i++;
    while (map[i] != '\n' && i > 2)
        i--;
    i--;
    while (map[i] != '\n' && i > 1)
        i--;
    i--;
    while (map[i] != '\n' && i > 0) {
        x++;
        i--;
    }
    x++;
    return (x);
}

int get_x_bot(char *map)
{
    int i = 0;
    int x = 0;

    while (map[i] != 'P'  && map[i] != '\0')
        i++;
    while (map[i] != '\n' && map[i] != '\0')
        i++;
    i++;
    while (map[i] != '\n' && map[i] != '\0')
        i++;
    i++;
    while (map[i] != '\n' && map[i] != '\0') {
        x++;
        i++;
    }
    x++;
    return (x);
}

char *map_update(char *m, int p, char *rem)
{
    int i = 0;
    int x = get_lign(m);
    int y = get_top_lign(m);

    while (m[i] != 'P')
        i++;
    if (i - y > 0)
        if (p == 65 && (m[i - y] == ' ' || m[i - y] == 'X' || m[i - y] == 'O'))
            m = manage_up(m, i, y, rem);
    if (p == 66 && (m[i + x] == ' ' || m[i + x] == 'X' || m[i + x] == 'O'))
        m = manage_low(m, i, x, rem);
    if (p == 67 && (m[i + 1] == ' ' || m[i + 1] == 'X' || m[i + 1] == 'O'))
        m = manage_right(m, i, rem);
    if (p == 68 && (m[i - 1] == ' ' || m[i - 1] == 'X' || m[i - 1] == 'O'))
        m = manage_left(m, i, rem);
    if (p == 32) {
        free(m);
        m = get_realloc(rem, my_strlen(rem));
    }
    return (m);
}
