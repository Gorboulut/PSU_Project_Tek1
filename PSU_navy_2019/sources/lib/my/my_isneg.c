/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** my_isneg.c
*/

void my_putchar(char c);

int my_isneg(int nb)
{
    if (nb >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}
