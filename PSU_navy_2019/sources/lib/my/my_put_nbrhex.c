/*
** EPITECH PROJECT, 2019
** my_put_nbrhex.c
** File description:
** my_put_nbrhex.c
*/

void my_putchar(char c);

void my_put_nbrhex(int n)
{
    long nb = n;
    int div = 1;
    char *base = "0123456789abcdef";

    for (; n / div > 9; div *= 16);
    for (int i = 0; div > 0; div /= 16) {
        i = n / div;
        my_putchar(base[i]);
        n -= (i * div);
    }
}
