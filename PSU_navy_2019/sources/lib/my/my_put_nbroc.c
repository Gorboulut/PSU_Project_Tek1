/*
** EPITECH PROJECT, 2019
** my_put_nbroc.c
** File description:
** my_put_nbroc.c
*/

void my_putchar(char c);

void my_put_nbroc(unsigned int n)
{
    int div = 1;
    char *base = "01234567";

    for (; n / div > 7; div *= 8);
    for (int i = 0; div > 0; div /= 8) {
        i = n / div;
        my_putchar(base[i]);
        n -= (i * div);
    }
}
