/*
** EPITECH PROJECT, 2019
** my_put_modp.c
** File description:
** my_put_modp.c
*/

void my_putchar(char c);

void my_putstr(char const *str);

void my_modp(int n)
{
    long nb = n;
    int div = 1;
    char *base = "0123456789abcdef";

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    my_putstr("0x");
    for (; nb / div > 9; div *= 16);
    for (int i = 0; div > 0; div /= 16) {
        i = nb / div;
        my_putchar(base[i]);
        nb -= (i * div);
    }
}
