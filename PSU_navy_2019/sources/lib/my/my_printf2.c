/*
** EPITECH PROJECT, 2019
** my_printf2.c
** File description:
** my_printf2.c
*/

#include "my.h"

void your_printf(char *s, va_list ap)
{
    int x = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '%') {
            i++;
            last_loop(s, x, i, ap);
        }
        else
            my_putchar(s[i]);
        i++;
    }
}

void last_loop(char *s, int x, int i, va_list ap)
{
    while (tabl[x].flag != 0) {
        if (tabl[x].flag == s[i])
            tabl[x].ptr(ap);
        x++;
    }
}

int my_printf(char *s, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, s);
    your_printf(s, ap);
    return (0);
}
