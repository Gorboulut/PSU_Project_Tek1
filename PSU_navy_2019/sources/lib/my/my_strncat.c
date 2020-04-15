/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** my_strncat.c
*/

int my_strlen(char *src);

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[length + i] = src[i];
    dest[i + length] = '\0';
    return (dest);
}
