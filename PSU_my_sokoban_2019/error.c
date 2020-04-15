/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** error
*/
#include <stdlib.h>

void check_error(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] != ' ' && map[i] != 'O' && map[i] != 'X' &&
            map[i] != '#' && map[i] != 'P' && map[i] != '\n')
            exit(84);
}
