/*
** EPITECH PROJECT, 2020
** map.c
** File description:
** map.c
*/
#include "sources/lib/my/my.h"

static int chosing_map_second(game_t *game, char **av)
{
    char *buff;

    buff = malloc(sizeof(char) + 32);
    if (open(av[2], O_RDONLY) == -1)
        return (4);
    if (read(open(av[2], O_RDONLY), buff, 32) == 0)
        return (4);
    buff[31] = '\0';
    game->tab = my_str_to_wordtab(buff, '\n');
    for (int i = 0; game->tab[i]; i++)
        if (my_strlen(game->tab[i]) != 7)
            return (4);
    return (0);
}

static int chosing_map(game_t *game, char **av)
{
    game->buffer = malloc(sizeof(char) + 32);
    if (open(av[1], O_RDONLY) == -1)
        return (4);
    if (read(open(av[1], O_RDONLY), game->buffer, 32) == 0)
        return (4);
    game->buffer[31] = '\0';
    game->tmp = my_str_to_wordtab(game->buffer, '\n');
    for (int i = 0; game->tmp[i]; i++)
        if (my_strlen(game->tmp[i]) != 7)
            return (4);
    return (0);
}

int chosing_map_text(game_t *game, char **av)
{
    if (game->ac == 2) {
        if (chosing_map(game, av) == 4)
            return (12);
        if (check_boat_first_map(game) == 11)
            return (12);
    }
    if (game->ac == 3) {
        if (chosing_map_second(game, av) == 4)
            return (12);
        if (check_boat_second_map(game) == 11)
            return (12);
    }
    return (0);
}
