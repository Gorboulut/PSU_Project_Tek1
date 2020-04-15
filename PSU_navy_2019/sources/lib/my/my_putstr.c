/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int w = 0; str[w] != '\0'; w++)
        my_putchar(str[w]);
}
