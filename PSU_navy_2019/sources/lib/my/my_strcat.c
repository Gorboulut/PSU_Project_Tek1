/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat.c
*/

int my_strlen(char *src);

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return (dest);
}
