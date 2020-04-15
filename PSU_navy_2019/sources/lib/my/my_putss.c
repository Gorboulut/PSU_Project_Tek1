/*
** EPITECH PROJECT, 2019
** my_putS.c
** File description:
** my_putS.c
*/

void my_putstr(char const *str);

void my_putchar(char c);

void my_put_nbroc(unsigned int);

void my_putss(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            if (str[i] < 8) {
                my_putstr("\\00");
                my_put_nbroc(str[i]);
            }
            if (str[i] < 32) {
                my_putstr("\\0");
                my_put_nbroc(str[i]);
            }
            if (str[i] >= 127) {
                my_putchar('\\');
                my_put_nbroc(str[i]);
            }
        }
        else
            my_putchar(str[i]);
    }
}
