/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin.h
*/

#ifndef LEMIN_H
#define LEMIN_H
#define UNUSED(x) (void)(x)

#include "../lib/my/my.h"
#include <stdio.h>

typedef struct addnode {
    int dest;
    struct addnode *next;
} add;

typedef struct graph {
    int v;
    struct addnode **list;
} graph;

typedef struct room {
    char *stat;
    struct room *next;
    struct room *prev;
} room_t;

typedef struct lemin {
    char *start;
    char *end;
    int v;
    room_t *room;
    room_t *tunnel;
} lem_t;

room_t *add_list(room_t *add, char *line);
int my_str_isnum(char const *str);
int parsing_nb_ants(lem_t *lem, graph *graph);
int call_graph(graph *graph);
char *get_nbr(char *line);
int print_nbr(char *line);
int check_line(char *c);
int go_end(char *line, size_t nb, lem_t *lem);
int go_start(char *line, size_t nb, lem_t *lem);
room_t *make_it_double(room_t *add);
int parsing_rooms(char *line, size_t nb, lem_t *lem, graph *graph);
int parsing_tunnels(char *line, size_t nb, lem_t *lem, graph *graph);
char *my_strcpy_mod(char *dest, char const *src);
char *my_strcpy_end(char *dest, char const *src);
void get_room_nbr(lem_t *lem, char *line);
void add_edge(graph *graph, int src, int dest);
graph *create_graph(int v);
void print_graph(graph *graph);

#endif /* !LEMIN_H */
