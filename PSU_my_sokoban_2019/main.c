/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban game
*/
#include <ncurses.h>
#include <stdlib.h>
#include "include/my.h"
#include <sys/stat.h>
#include <stdarg.h>
#include <fcntl.h>

char *get_realloc(char *fullstr, int len)
{
    char *newstr = NULL;
    int i = 0;

    if (fullstr == NULL)
        return (my_strdup(fullstr));
    newstr = malloc(sizeof(char) + (len + 1));
    while (fullstr[i] != '\0') {
        newstr[i] = fullstr[i];
        i++;
    }
    newstr[i] = '\0';
    return (newstr);
}

int get_win_lose(char *map, char *rem, int o, int w)
{
    int x = get_lign(map);
    int check_win = 0;

    for (int i = 0; rem[i] != '\0'; i++) {
        if (rem[i] == 'O' && map[i] == 'X')
            check_win++;
        if (check_win == o) {
            free(rem);
            free(map);
            endwin();
            exit(0);
        }
    }
    get_lose(map, rem, w, x);
    return (2);
}

int start_sok(char *extend, struct stat op)
{
    char *rem = NULL;
    int pressed;
    int o = o_detect(extend);
    int x = x_detect(extend);

    initscr();
    noecho();
    rem = get_realloc(extend, op.st_size);
    while (1) {
        mvprintw(0, 0, extend);
        pressed = getch();
        extend = map_update(extend, pressed, rem);
        refresh();
        get_win_lose(extend, rem, o, x);
        if (pressed == 109) {
            endwin();
            free(rem);
            return (0);
        }
    }
}

int create_map(char **av)
{
    char *extend;
    char *str;
    struct stat op;
    int fd;

    stat(av[1], &op);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    extend = NULL;
    str = malloc(sizeof(char) + op.st_size);
    read(fd, str, op.st_size);
    str[op.st_size] = '\0';
    extend = get_realloc(str, op.st_size);
    extend[op.st_size] = '\0';
    free(str);
    check_error(extend);
    start_sok(extend, op);
    free(extend);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, containing");
        my_putstr("'#' for walls, 'P' for the player, 'X' for boxes and 'O'");
        my_putstr(" for storage locations\n");
        return (0);
    }
    create_map(av);
    return (0);
}
