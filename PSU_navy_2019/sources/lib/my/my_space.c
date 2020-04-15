/*
** EPITECH PROJECT, 2019
** my_space.c
** File description:
** my_space.c
*/

#include <stdarg.h>
#include "my.h"

void my_space(char const *str)
{
    for (int i = 0; str[i] == 32;) {
        my_putchar(32);
        i++;
    }
}

void my_space_va(va_list ap)
{
    my_space(va_arg(ap, char *));
}
