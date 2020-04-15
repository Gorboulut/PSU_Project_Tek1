/*
** EPITECH PROJECT, 2020
** navy
** File description:
** recreate a naval battle
*/
#include "sources/lib/my/my.h"

int game_win(game_t *game)
{
    if (game->ac == 2) {
        if (game->win_p1 == 14) {
            my_putstr("\nI won\n");
            return (0);
        } else {
            my_putstr("\nEnemy won\n");
            return (1);
        }
    }
    if (game->ac == 3) {
        if (game->win_p2 == 14) {
            my_putstr("\nI won\n");
            return (0);
        }
        my_putstr("\nEnemy won\n");
        return (1);
    }
    return (0);
}

void connect_player(int ac, char **av)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    if (ac == 2) {
        my_putstr("waiting for enemy connection...\n");
        pause();
        my_putstr("\nenemy connected\n");
    }
    else if (ac == 3) {
        sig.pid = my_getnbr(av[1]);
        usleep(10000);
        kill(sig.pid, 12);
        usleep(10000);
        my_putstr("successfully connected\n");
    }
}

int main(int ac, char **av)
{
    struct game_s *game = malloc(sizeof(game_t));

    if (ac == 1)
        return (84);
    game->ac = ac;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        helper_navy();
        return (0);
    }
    if (chosing_map_text(game, av) == 12)
        return (84);
    if (check_lenght_boat(game) == 84)
        return (84);
    connect_pid(10);
    connect_pid(12);
    connect_player(ac, av);
    our_map(game, av);
    translate_map(game);
    start_game(ac, game);
    return (game_win(game));
}
