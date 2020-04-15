/*
** EPITECH PROJECT, 2020
** navy
** File description:
** p1 and p2 func
*/
#include "sources/lib/my/my.h"

int p1_func(game_t *game, int posx, int posy)
{
    my_putstr("\nmy positions:\n");
    for (int i = 0; game->maps.p1_hit[i] != NULL; i++)
        my_printf("%s\n", game->maps.p1_hit[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; game->maps.p1_map[i] != NULL; i++)
        my_printf("%s\n", game->maps.p1_map[i]);
    if (player_attack(game, 1) == 84)
        return (84);
    if (get_win(game) == 1)
        return (1);
    player1_turn(game, posx, posy);
    return (0);
}

int p2_func(game_t *game, int posx, int posy)
{
    my_printf("\n%s\n", "my positions:");
    for (int i = 0; game->maps.p2_hit[i] != NULL; i++)
        my_printf("%s\n", game->maps.p2_hit[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0;  game->maps.p2_map[i] != NULL; i++)
        my_printf("%s\n", game->maps.p2_map[i]);
    player2_turn(game, posx, posy);
    if (get_win(game) == 1)
        return (1);
    if (player_attack(game, 2) == 84)
        return (84);
    return (0);
}

void player1_turn(game_t *game, int posx, int posy)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    sig.sig1 = 0;
    sig.sig2 = 0;
    posx = 0;
    posy = 0;
    while (sig.sig2 == 0);
    posx = sig.sig1++;
    sig.sig1 = 0;
    sig.sig2 = 0;
    while (sig.sig2 == 0);
    posy = sig.sig1++;
    sig.sig1 = 0;
    sig.sig2 = 0;
    my_printf("%c%c: ", posx + 15 + '0', posy + '0' - 1);
    check_hit_defence_p1(game, posx, posy);
}

void player2_turn(game_t *game, int posx, int posy)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    sig.sig1 = 0;
    sig.sig2 = 0;
    posx = 0;
    posy = 0;
    while (sig.sig2 == 0);
    posx = sig.sig1++;
    sig.sig1 = 0;
    sig.sig2 = 0;
    while (sig.sig2 == 0);
    posy = sig.sig1++;
    sig.sig1 = 0;
    sig.sig2 = 0;
    my_printf("%c%c: ", posx + 15 + '0', posy + '0' - 1);
    check_hit_defence_p2(game, posx, posy);
}
