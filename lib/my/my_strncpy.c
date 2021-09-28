/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** lib
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int idx = 0;

    while (idx < n && src[idx]) {
        dest[idx] = src[idx];
        idx += 1;
    }
    dest[idx] = '\0';
    return (dest);
}

