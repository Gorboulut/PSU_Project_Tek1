/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H
#define UNUSED(x) (void)(x)

#include <sys/sysmacros.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

typedef struct struct_s {
    char *buffer;
    char **tab;
    char *tmp;
    int i;
    size_t size_t;
    char *s;
    char *yes;
    char *tmp3_buffer;
    char **stock;
} struct_t;

typedef struct map_s {
    char **p1_map;
    char **p1_hit;
    char **p2_map;
    char **p2_hit;
} map_t;

typedef struct boat_s {
    int x1;
    int x2;
    int y1;
    int y2;
    char lign;
    int lenght;
} boat_t;

typedef struct lboat_s {
    int x1;
    int x2;
    int y1;
    int y2;
    int lenght;
} lboat_t;

typedef struct game_s {
    char **map;
    int ac;
    int x;
    int y;
    int z;
    int win_p1;
    int win_p2;
    char **tmp;
    char **tab;
    char **tmp2;
    char *buffer;
    int k;
    int w;
    int j;
    char *t;
    lboat_t bt;
    map_t maps;
    boat_t boat;
} game_t;

typedef struct signal_s {
    int pid;
    int sig1;
    int sig2;
} signal_t;

signal_t sig;

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int n);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_printf(char *s, ...);
void fl_mod(char *str);
void ptr_fct(void(*ptr[])(va_list));
void my_putni_va(va_list ap);
void my_putc_va(va_list ap);
void my_puts_va(va_list ap);
void my_putn_va(va_list ap);
void your_printf(char *s, va_list ap);
void my_put_nbrhex_va(va_list ap);
void my_put_nbrhexc_va(va_list ap);
void my_put_nbrhex(int n);
void my_put_nbrhexc(int n);
void my_put_nbrun(unsigned int n);
void my_put_nbrbi(unsigned int n);
void my_put_nbrbi_va(va_list ap);
void my_put_nbroc(unsigned int n);
void my_put_nbroc_va(va_list ap);
void my_modp(int n);
void my_modp_va(va_list ap);
void my_putss_va(va_list ap);
void my_putss(char const *str);
void last_loop(char *s, int x, int i, va_list ap);
void my_space(char const *str);
void my_space_va(va_list ap);
void addprintf(char *s, int i, int x, va_list ap);
void my_mod_print_va(va_list ap);
int flags(char *str, struct dirent *d, DIR *dir);
int ls(struct dirent *d, DIR *dir);
int ls_base(struct dirent *d, DIR *dir);
int count(struct dirent *d, DIR *dir);
int ls_rflag(struct dirent *d, DIR *dir, int ct);
int ls_file(char *str, struct dirent *d, DIR *dir);
int ls_lflag(struct dirent *d, DIR *dir);
int my_chmod(struct dirent *d);
int my_tmp(int tmp);
int my_tmp2(int tmp2);
int my_tmp3(int tmp3);
int flag_a_r_l(char *str, int i, struct dirent *d, DIR *dir);
int my_group(struct stat sb);
int ls_lflag_s(struct dirent *d, DIR *dir, struct stat sb);
int game(struct struct_s *stru, char **av);
int my_user(struct stat sb);
int my_links(struct stat sb);
int map(char **av, struct struct_s stru);
int settings(struct struct_s *stru, char **av);
void algo(struct struct_s *stru);
int removing_sticks(struct struct_s *stru);
int removing_sticks_bot(struct struct_s *stru);
int random_bot(struct struct_s *stru);
char **my_str_to_wordtab(char *str, char c);
int prompt_command(struct_t stru, char **env);
int my_setenv(struct_t stru, char **env);
int my_pwd(struct_t stru);
void my_env(char **env);
void my_cd_base(char **env);
void my_cd(struct_t stru, char **env);
char *clean_string(struct_t stru);
char *my_strcat2(char *dest, char const *src);
void my_path(struct_t stru, char **env);
void ft_ls(struct_t stru, char **env);
int my_str_start_with(char *str, char *str2);
int our_map(game_t *game, char **av);
void connect_pid(int pid);
void connect_player(int ac, char **av);
void handler(int sign, siginfo_t *info, void *ucontext);
int start_game(int ac, struct game_s *game);
void translate_map(game_t *game);
char *get_realloc(char *fullstr, int len);
char *my_strdup(char const *src);
int check_hit_p1(game_t *game, int x, int y);
void get_pos_boat_2p(game_t *game);
char *my_strcpy(char *dest, char const *src);
int player_attack(struct game_s *game, int i);
void check_hit_defence_p2(game_t *game, int x, int y);
void check_hit_defence_p1(game_t *game, int x, int y);
int check_hit_p2(game_t *game, int x, int y);
int get_win(game_t *game);
int check_boat_first_map(struct game_s *game);
int check_boat_second_map(struct game_s *game);
int chosing_map_text(game_t *game, char **av);
void send_signal(int x, int y);
void player1_turn(game_t *game, int posx, int posy);
void player2_turn(game_t *game, int posx, int posy);
int p2_func(game_t *game, int posx, int posy);
int p1_func(game_t *game, int posx, int posy);
int check_lenght_boat(game_t *game);
void player2_turn(game_t *game, int posx, int posy);
void player1_turn(game_t *game, int posx, int posy);
void helper_navy(void);

typedef struct flag_s {
    char flag;
    void (*ptr)(va_list);
} flag_t;

static const flag_t tabl[] = {
    {'s', &my_puts_va},
    {'c', &my_putc_va},
    {'d', &my_putn_va},
    {'i', &my_putn_va},
    {'u', &my_putni_va},
    {'o', &my_put_nbroc_va},
    {'x', &my_put_nbrhex_va},
    {'X', &my_put_nbrhexc_va},
    {'p', &my_modp_va},
    {'b', &my_put_nbrbi_va},
    {'S', &my_putss_va},
    {'%', &my_mod_print_va},
    {0}
};

#endif
