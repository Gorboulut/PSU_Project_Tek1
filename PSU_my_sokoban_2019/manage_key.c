/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban game
*/
#include "include/my.h"

int get_x_bottwo(char *map)
{
    int i = 0;
    int x = 0;

    while (map[i] != 'P')
        i++;
    while (map[i] != '\n')
        i++;
    i++;
    while (map[i] != '\n') {
        x++;
        i++;
    }
    x++;
    return (x);
}

char *manage_up(char *map, int i, int x, char *rem)
{
    int w = get_x_top(map);

    if (map[i - x] == ' ') {
        map[i - x] = 'P';
        map[i] = rem[i];
    }
    if (map[i - x] == 'X' && (map[i - x - w] == ' ' || map[i - x - w] == 'O')) {
        map[i - x] = 'P';
        map[i - x - w] = 'X';
        map[i] = rem[i];
    }
    if (map[i - x] == 'O') {
        map[i - x] = 'P';
        map[i] = rem[i];
    }
    if ((map[i] == 'P' && map[i - x] == 'P') || map[i] == 'X')
        map[i] = ' ';
    return (map);
}

char *manage_low(char *map, int i, int x, char *rem)
{
    int z = get_x_bottwo(map);

    if (map[i + x] == ' ') {
        map[i + x] = 'P';
        map[i] = rem[i];
    }
    if (map[i + x] == 'X' && (map[i + z + x] == ' ' || map[i + x + z] == 'O')) {
        map[i + x] = 'P';
        map[i + x + z] = 'X';
        map[i] = rem[i];
    }
    if (map[i + x] == 'O') {
        map[i + x] = 'P';
        map[i] = rem[i];
    }
    if ((map[i] == 'P' && map[i + x] == 'P') || map[i] == 'X')
        map[i] = ' ';
    return (map);
}

char *manage_right(char *map, int i, char *rem)
{
    if (map[i + 1] == ' ') {
        map[i + 1] = 'P';
        map[i] = rem[i];
    }
    if (map[i + 1] == 'X' && (map[i + 1 + 1] == ' ' || map[i + 1 + 1] == 'O')) {
        map[i + 1] = 'P';
        map[i + 1 + 1] = 'X';
        map[i] = rem[i];
    }
    if (map[i + 1] == 'O') {
        map[i + 1] = 'P';
        map[i] = rem[i];
    }
    if ((map[i] == 'P' && map[i + 1] == 'P') || map[i] == 'X')
        map[i] = ' ';
    return (map);
}

char *manage_left(char *map, int i, char *rem)
{
    if (map[i - 1] == ' ') {
        map[i - 1] = 'P';
        map[i] = rem[i];
    }
    if (map[i - 1] == 'X' && (map[i - 1 - 1] == ' ' || map[i - 1 - 1] == 'O')) {
        map[i - 1] = 'P';
        map[i - 1 - 1] = 'X';
        map[i] = rem[i];
    }
    if (map[i - 1] == 'O') {
        map[i - 1] = 'P';
        map[i] = rem[i];
    }
    if ((map[i] == 'P' && map[i - 1] == 'P') || map[i] == 'X')
        map[i] = ' ';
    return (map);
}
