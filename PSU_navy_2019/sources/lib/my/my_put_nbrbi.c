/*
** EPITECH PROJECT, 2019
** my_put_nbrbi.c
** File description:
** my_put_nbrbi.c
*/

void my_putchar(char c);

void my_put_nbrbi(unsigned int n)
{
    int div = 1;
    char *base = "01";

    for (; n / div > 1; div *= 2);
    for (int i = 0; div > 0; div /= 2) {
        i = n / div;
        my_putchar(base[i]);
        n -= (i * div);
    }
}
