/*
** EPITECH PROJECT, 2020
** navy
** File description:
** calling game
*/
#include "sources/lib/my/my.h"

void send_signal(int x, int y)
{
    sig.sig2 = 0;
    usleep(50000);
    for (int w = 0; w < x; w++) {
        kill(sig.pid, 10);
        usleep(2000);
    }
    kill(sig.pid, 12);
    usleep(1000);
    for (int z = 0; z < y; z++) {
        kill(sig.pid, 10);
        usleep(2000);
    }
    kill(sig.pid, 12);
    usleep(1000);
}

int p1_attack_turn(game_t *game, int x, int y, char *buff)
{
    my_printf("%s: ", buff);
    send_signal(x, y);
    check_hit_p1(game, x, y);
    free(buff);
    return (0);
}

int p2_attack_turn(game_t *game, int x, int y, char *buff)
{
    my_printf("%s: ", buff);
    send_signal(x, y);
    check_hit_p2(game, x, y);
    free(buff);
    return (0);
}

int player_attack(struct game_s *game, int i)
{
    int x = 0;
    int y = 0;
    char *buff = malloc(sizeof(char) * 10);

    my_printf("\nattack: ");
    for (int i = 0; i < 10; i++) buff[i] = '\0';
    if (read(0, buff, 10) == -1) return (84);
    if (buff[0] != '\0') {
        x = buff[0] - 15 - '0';
        y = buff[1] - '0' + 1;
    }
    if (x > 9 || y > 9 || x < 2 || y < 2 || my_strlen(buff) > 3) {
        my_putstr("wrong position");
        free(buff);
        return (player_attack(game, i));
    } buff[2] = '\0';
    if (i == 1) if (p1_attack_turn(game, x, y, buff) == 84)
            return (player_attack(game, i));
    if (i == 2) if (p2_attack_turn(game, x, y, buff) == 84)
            return (player_attack(game, i));
    return (0);
}

int start_game(int ac, struct game_s *game)
{
    int posx = 0;
    int posy = 0;

    game->win_p1 = 0;
    game->win_p2 = 0;
    while (1) {
        if (ac == 2) {
            if (p1_func(game, posx, posy == 84))
                return (84);
            if (get_win(game) == 1)
                return (1);
        }
        else {
            if (p2_func(game, posx, posy) == 1)
                return (1);
            if (get_win(game) == 1)
                return (0);
        }
    }
    return (0);
}
