/*
** EPITECH PROJECT, 2019
** va.c
** File description:
** va.c
*/

#include <stdarg.h>
#include "my.h"

void my_putni_va(va_list ap)
{
    my_put_nbrun(va_arg(ap, unsigned int));
}

void my_putc_va(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void my_puts_va(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void my_putn_va(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void my_putss_va(va_list ap)
{
    my_putss(va_arg(ap, char *));
}
