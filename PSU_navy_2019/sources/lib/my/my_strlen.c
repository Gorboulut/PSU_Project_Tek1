/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++);
    return (i);
}
