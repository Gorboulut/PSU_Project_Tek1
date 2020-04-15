/*
** EPITECH PROJECT, 2019
** my_print_digits.c
** File description:
** my_print_digits.c
*/

void my_putchar(char c);

int my_print_digits(void)
{
    char print = 48;

    while (print <= 57) {
        my_putchar(print);
        print++;
    }
    return (0);
}
