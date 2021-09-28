/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** lib
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (FALSE);
    while (s1[i]) {
        if (s1[i] != s2[i]) {
            return (FALSE);
        }
        i = i + 1;
    }
    return (TRUE);
}
