/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** my_print_alpha.c
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    char print = 97;

    while (print <= 122) {
        my_putchar(print);
        print++;
    }
    return (0);
}
