/*
** EPITECH PROJECT, 2019
** my_put_nbrun.c
** File description:
** my_put_nbrun.c
*/

void my_putchar(char c);

void my_put_nbrun(unsigned int n)
{
    int div = 1;

    for (; n / div > 9; div *= 10);
    for (int i = 0; div > 0; div /= 10) {
        i = n / div;
        my_putchar(i + '0');
        n -= (i * div);
    }
}
