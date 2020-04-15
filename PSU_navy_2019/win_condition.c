/*
** EPITECH PROJECT, 2020
** navy
** File description:
** win condition for the navy
*/
#include "sources/lib/my/my.h"

int check_p1_win(game_t *game)
{
    if (game->ac == 2) {
        my_printf("\n%s\n", "my positions:");
        for (int i = 0; game->maps.p1_hit[i] != NULL; i++)
            my_printf("%s\n", game->maps.p1_hit[i]);
        my_printf("\nenemy's positions:\n");
        for (int i = 0;  game->maps.p1_map[i] != NULL; i++)
            my_printf("%s\n", game->maps.p1_map[i]);
        return (1);
    }
    if (game->ac == 3) {
        my_printf("\n%s\n", "my positions:");
        for (int i = 0; game->maps.p2_hit[i] != NULL; i++)
            my_printf("%s\n", game->maps.p2_hit[i]);
        my_printf("\nenemy's positions:\n");
        for (int i = 0;  game->maps.p2_map[i] != NULL; i++)
            my_printf("%s\n", game->maps.p2_map[i]);
        return (1);
    }
    return (1);
}

int check_p2_win(game_t *game)
{
    if (game->ac == 2) {
        my_printf("\n%s\n", "my positions:");
        for (int i = 0; game->maps.p1_hit[i] != NULL; i++)
            my_printf("%s\n", game->maps.p1_hit[i]);
        my_printf("\nenemy's positions:\n");
        for (int i = 0;  game->maps.p1_map[i] != NULL; i++)
            my_printf("%s\n", game->maps.p1_map[i]);
        return (1);
    }
    if (game->ac == 3) {
        my_printf("\n%s\n", "my positions:");
        for (int i = 0; game->maps.p2_hit[i] != NULL; i++)
            my_printf("%s\n", game->maps.p2_hit[i]);
        my_printf("\nenemy's positions:\n");
        for (int i = 0;  game->maps.p2_map[i] != NULL; i++)
            my_printf("%s\n", game->maps.p2_map[i]);
        return (1);
    }
    return (1);
}

int get_win(game_t *game)
{
    if (game->win_p1 == 14) {
        check_p1_win(game);
        return (1);
    }
    if (game->win_p2 == 14) {
        check_p2_win(game);
        return (1);
    }
    return (0);
}
