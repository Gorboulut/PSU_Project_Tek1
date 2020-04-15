/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** win and losing condition
*/
#include "include/my.h"
#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>

int get_loose(char *map, int x, int i)
{
    if (map[i] == 'X' && map[i + x]  == '#' &&
        (map[i + 1] == '#' || map[i - 1] == '#'))
        return (1);
    if (map[i] == 'X' && map[i - x]  == '#' &&
        (map[i + 1] == '#' || map[i - 1] == '#'))
        return (1);
    if (map[i] == 'X' && map[i - 1]  == '#' &&
        (map[i - x] == '#' || map[i + x] == '#'))
        return (1);
    if (map[i] == 'X' && map[i + 1]  == '#' &&
        (map[i + x] == '#' || map[i - x] == '#'))
        return (1);
    return (0);
}

int get_lose(char *map, char *rem, int w, int x)
{
    int loose = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'X')
            if (get_loose(map, x, i) == 1)
                loose++;
        if (loose == w) {
            free(rem);
            free(map);
            endwin();
            exit(1);
        }
    }
    return (0);
}

int o_detect(char *extend)
{
    int x = 0;

    for (int i = 0; extend[i] != '\0'; i++)
        if (extend[i] == 'O')
            x++;
    return (x);
}

int x_detect(char *extend)
{
    int x = 0;

    for (int i = 0; extend[i] != '\0'; i++)
        if (extend[i] == 'X')
            x++;
    return (x);
}

