/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
** my_print_revalpha.c
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    char print = 122;

    while (print >= 97) {
        my_putchar(print);
        print--;
    }
    return (0);
}
