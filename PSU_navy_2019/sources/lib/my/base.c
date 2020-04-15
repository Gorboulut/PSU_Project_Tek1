/*
** EPITECH PROJECT, 2019
** base.c
** File description:
** base.c
*/

#include <stdarg.h>
#include "my.h"

void my_put_nbrhex_va(va_list ap)
{
    my_put_nbrhex(va_arg(ap, int));
}

void my_put_nbrhexc_va(va_list ap)
{
    my_put_nbrhexc(va_arg(ap, int));
}

void my_put_nbroc_va(va_list ap)
{
    my_put_nbroc(va_arg(ap, unsigned int));
}

void my_put_nbrbi_va(va_list ap)
{
    my_put_nbrbi(va_arg(ap, unsigned int));
}

void my_modp_va(va_list ap)
{
    my_modp(va_arg(ap, int));
}
