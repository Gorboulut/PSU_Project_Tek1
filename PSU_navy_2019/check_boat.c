/*
** EPITECH PROJECT, 2020
** check_boat.c
** File description:
** check_boat.c
*/

#include "sources/lib/my/my.h"

int check_boat_first_map(struct game_s *game)
{
    int nb = 0;
    int i;

    for (i = 0; game->tmp[i] != NULL; i++) {
        if (game->tmp[i][0] < 50 || game->tmp[i][0] > 53)
            return (11);
        else
            nb = nb + game->tmp[i][0] - '0';
    }
    if (i != 4)
        return (11);
    if (nb != 14)
        return (11);
    return (0);
}

int check_boat_second_map(struct game_s *game)
{
    int nb = 0;
    int i;

    for (i = 0; game->tab[i] != NULL; i++) {
        if (game->tab[i][0] < 50 || game->tab[i][0] > 53)
            return (11);
        else
            nb = nb + game->tab[i][0] - '0';
    }
    if (i != 4)
        return (11);
    if (nb != 14)
        return (11);
    return (0);
}
