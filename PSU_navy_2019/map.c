/*
** EPITECH PROJECT, 2020
** map.c
** File description:
** map.c
*/

#include "sources/lib/my/my.h"

char **setting_map(game_t *game, char **str)
{
    str = malloc(sizeof(char * ) * 12);

    for (int i = 0; i < 11; i++)
        str[i] = malloc(sizeof(char) * 18);
    str[0][0] = ' ';
    game->y = 2;
    for (int i = 65; i != 73; i++, game->y++) {
        str[0][game->y] = i;
        game->y++;
        str[0][game->y] = ' ';
    }
    str[0][17] = '\0';
    str[11] = NULL;
    return (str);
}

char **setting_game_area(game_t *game, char **str)
{
    for (game->z = 3, game->x = 2, game->w = 2; str[game->x]; game->x++) {
        for (; game->w < 17;) {
            str[game->x][game->z] = ' ';
            str[game->x][game->w] = '.';
            game->z = game->z + 2;
            game->w = game->w + 2;
            str[game->x][17] = '\0';
        }
        game->z = 3;
        game->w = 2;
    }
    return (str);
}

int update_struct_2(game_t *game, char **str)
{
    int i = 0;

    game->maps.p1_map = malloc(sizeof(char * ) * 12);
    game->maps.p1_hit = malloc(sizeof(char * ) * 12);
    game->maps.p2_map = malloc(sizeof(char * ) * 12);
    game->maps.p2_hit = malloc(sizeof(char * ) * 12);
    if (game->ac == 2) {
        for (; str[i] != NULL; i++) {
            game->maps.p1_map[i] = my_strcpy(game->maps.p1_map[i], str[i]);
            game->maps.p1_hit[i] = my_strcpy(game->maps.p1_hit[i], str[i]);
        }
    }
    if (game->ac == 3) {
        for (i = 0; str[i] != NULL; i++) {
            game->maps.p2_map[i] = my_strcpy(game->maps.p2_map[i], str[i]);
            game->maps.p2_hit[i] = my_strcpy(game->maps.p2_hit[i], str[i]);
        }
    }
    return (i);
}

void update_struct(game_t *game, char **str)
{
    int i = 0;

    str[1][1] = '+';
    str[1][17] = '\0';
    str[10][17] = '\0';
    str[10] = NULL;
    i = update_struct_2(game, str);
    game->maps.p1_map[i] = NULL;
    game->maps.p1_hit[i] = NULL;
    game->maps.p2_map[i] = NULL;
    game->maps.p2_hit[i] = NULL;
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

int our_map(game_t *game, char **av)
{
    char **str = NULL;

    UNUSED(av);
    str = setting_map(game, str);
    str = setting_game_area(game, str);
    game->y = 0;
    for (int j = 0; j != 17; j++, game->y++)
        str[1][game->y] = '-';
    game->x = 2;
    for (int i = 1; i != 9; i++, game->x++)
        str[game->x][0] = i + 48;
    game->x = 0;
    for (int i = 0; i != 11; i++, game->x++)
        str[game->x][1] = '|';
    update_struct(game, str);
    return (0);
}
