/*
** EPITECH PROJECT, 2020
** navy
** File description:
** translate the text file
*/
#include "sources/lib/my/my.h"

void look_other_axes(int y_axe, int x_axe, game_t *game)
{
    int w = 0;

    if (x_axe > 0)
        for (; game->boat.lenght > 0; game->boat.lenght--) {
            game->maps.p1_hit[game->boat.y2 + 1 + w][(game->boat.x1 * 2) + 2]
            = game->boat.lign;
            w++;
        }
    else if (y_axe > 0)
        for (; game->boat.lenght > 0; game->boat.lenght--) {
            game->maps.p1_hit[game->boat.y1 + 1][(game->boat.x2 * 2)
            + 2 + (w * 2)] = game->boat.lign;
            w++;
        }
}

void get_lenght_boat(game_t *game)
{
    int w = 0;
    int y_axe = game->boat.x1 - game->boat.x2;
    int x_axe = game->boat.y1 - game->boat.y2;

    if (x_axe < 0)
        for (; game->boat.lenght > 0; game->boat.lenght--) {
            game->maps.p1_hit[game->boat.y2 + 1 - w][(game->boat.x1 * 2) + 2]
            = game->boat.lign;
            w++;
        }
    else if (y_axe < 0)
        for (; game->boat.lenght > 0; game->boat.lenght--) {
            game->maps.p1_hit[game->boat.y1 + 1][(game->boat.x1 * 2)
            + 2 + (w * 2)] = game->boat.lign;
            w++;
        }
    else
        look_other_axes(y_axe, x_axe, game);
}

void get_pos_boat(game_t *game)
{
    for (int i = 0; game->tmp[i] != NULL; i++) {
        game->boat.x1 = game->tmp[i][2] - 65;
        game->boat.x2 = game->tmp[i][5] - 65;
        game->boat.y1 = game->tmp[i][3] - 48;
        game->boat.y2 = game->tmp[i][6] - 48;
        game->boat.lenght = game->tmp[i][0] - 49;
        game->boat.lign = game->tmp[i][0];
        game->maps.p1_hit[game->boat.y1 + 1][(game->boat.x1 * 2) + 2]
        = game->tmp[i][0];
        game->maps.p1_hit[game->boat.y2 + 1][(game->boat.x2 * 2) + 2]
        = game->tmp[i][0];
        get_lenght_boat(game);
    }
}

void translate_map(game_t *game)
{
    if (game->ac == 2) {
        get_pos_boat(game);
    }
    if (game->ac == 3) {
        get_pos_boat_2p(game);
    }
}
