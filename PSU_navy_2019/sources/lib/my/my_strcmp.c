/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if ((s1[i] - s2[i]) == 0)
        return (0);
    else
        return (-1);
}
