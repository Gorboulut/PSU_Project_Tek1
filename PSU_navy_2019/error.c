/*
** EPITECH PROJECT, 2020
** navy
** File description:
** error management
*/
#include "sources/lib/my/my.h"

int check_lenght_boat_p1(game_t *game)
{
    int res = 0;

    for (int i = 0; game->tmp[i] != NULL; i++) {
        game->bt.x1 = game->tmp[i][2] - 'A';
        game->bt.x2 = game->tmp[i][5] - 'A';
        game->bt.y1 = game->tmp[i][3] - '0';
        game->bt.y2 = game->tmp[i][6] - '0';
        game->bt.lenght = game->tmp[i][0] - '0' - 1;
        res = game->bt.x1 - game->bt.x2;
        if (res != 0 && res != game->bt.lenght && res != (game->bt.lenght) * -1)
            return (84);
        res = game->bt.y1 - game->bt.y2;
        if (res != 0 && res != game->bt.lenght && res != (game->bt.lenght) * -1)
            return (84);
    }
    return (0);
}

int check_lenght_boat_p2(game_t *game)
{
    int res = 0;

    for (int i = 0; game->tab[i] != NULL; i++) {
        game->bt.x1 = game->tab[i][2] - 'A';
        game->bt.x2 = game->tab[i][5] - 'A';
        game->bt.y1 = game->tab[i][3] - '0';
        game->bt.y2 = game->tab[i][6] - '0';
        game->bt.lenght = game->tab[i][0] - '0' - 1;
        res = game->bt.x1 - game->bt.x2;
        if (res != 0 && res != game->bt.lenght && res != (game->bt.lenght) * -1)
            return (84);
        res = game->bt.y1 - game->bt.y2;
        if (res != 0 && res != game->bt.lenght && res != (game->bt.lenght) * -1)
            return (84);
    }
    return (0);
}

int check_lenght_boat(game_t *game)
{
    if (game->ac == 2)
        if (check_lenght_boat_p1(game) == 84)
            return (84);
    if (game->ac == 3)
        if (check_lenght_boat_p2(game) == 84)
            return (84);
    return (0);
}
