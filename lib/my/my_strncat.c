/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** lib
*/

#include "../../include/my.h"

char *my_strncat(char *dest , char  const *src , int nb)
{
    int		idx_dest;
    int		idx_src;

    idx_dest = my_strlen(dest);
    idx_src = 0;
    while (idx_src < nb && src[idx_src]) {
        dest[idx_dest] = src[idx_src];
        idx_dest += 1;
        idx_src += 1;
    }
    dest[idx_dest] = '\0';
    return (dest);
}
