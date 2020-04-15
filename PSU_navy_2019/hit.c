/*
** EPITECH PROJECT, 2020
** navy
** File description:
** check hit
*/
#include "sources/lib/my/my.h"

int check_hit_p1(game_t *game, int x, int y)
{
    while (sig.sig2 == 0);
    if (sig.sig1 == 1) {
        my_putstr("hit\n");
        game->win_p1++;
        game->maps.p1_map[y][(x * 2) - 2] = 'x';
    }
    else {
        my_putstr("missed\n");
        game->maps.p1_map[y][(x * 2) - 2] = 'o';
    }
    sig.sig1 = 0;
    sig.sig2 = 0;
    return (0);
}

void check_hit_defence_p2(game_t *game, int x, int y)
{
    if (game->maps.p2_hit[y][(x * 2) - 2] > '1' &&
        game->maps.p2_hit[y][(x * 2) - 2] < '6') {
            game->maps.p2_hit[y][(x * 2) - 2] = 'x';
            my_putstr("hit\n");
            usleep(1000);
            kill(sig.pid, 10);
            usleep(1000);
            game->win_p1++;
    }
    else {
        game->maps.p2_hit[y][(x * 2) - 2] = 'o';
        my_putstr("missed\n");
    }
    kill(sig.pid, 12);
    usleep(1000);
}

int check_hit_p2(game_t *game, int x, int y)
{
    while (sig.sig2 == 0);
    if (sig.sig1 == 1) {
        my_putstr("hit\n");
        game->maps.p2_map[y][(x * 2) - 2] = 'x';
        game->win_p2++;
    }
    else {
        my_putstr("missed\n");
        game->maps.p2_map[y][(x * 2) - 2] = 'o';
    }
    sig.sig1 = 0;
    sig.sig2 = 0;
    return (0);
}

void check_hit_defence_p1(game_t *game, int x, int y)
{
    if (game->maps.p1_hit[y][(x * 2) - 2] > '1' &&
        game->maps.p1_hit[y][(x * 2) - 2] < '6') {
            game->maps.p1_hit[y][(x * 2) - 2] = 'x';
            my_putstr("hit\n");
            usleep(1000);
            kill(sig.pid, 10);
            usleep(1000);
            game->win_p2++;
    }
    else {
        game->maps.p1_hit[y][(x * 2) - 2] = 'o';
        my_putstr("missed\n");
    }
    kill(sig.pid, 12);
    usleep(1000);
}
