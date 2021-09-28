/*
** EPITECH PROJECT, 2021
** UTILS
** File description:
** utils
*/

#include "./include/mysh.h"

char *trim (char *str)
{
    char *ibuf, *obuf;

    if (str) {
        for (ibuf = obuf = str; *ibuf;) {
            while (*ibuf && (*ibuf == ' '))
                ibuf++;
            if (*ibuf && (obuf != str))
                *(obuf++) = ' ';
            while (*ibuf && (*ibuf != ' '))
                *(obuf++) = *(ibuf++);
        }
        *obuf = '\0';
    }
    return (str);
}

char *clean_str(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '\t' || str[i] == '\n') {
            str[i] = ' ';
        }
        i++;
    }
    return (trim(str));
}

int array_len(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}

void str_contains2(int *s, int *found, int *t)
{
    *s -= *found;
    *found = 0;
    *t = 0;
}

int str_contains(char *string, char *tofind)
{
    int slen = my_strlen(string);
    int tflen = my_strlen(tofind);
    int found = 0;

    if (slen >= tflen ) {
        for (int s = 0, t = 0; s < slen; s++) {
            do {
                if (string[s] == tofind[t]) {
                    if (++found == tflen) return 1;
                    s++;
                    t++;
                }
                else {
                    str_contains2(&s, &found, &t);
                }
            } while (found);
        }
        return 0;
    } else
        return -1;
}