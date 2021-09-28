/*
** EPITECH PROJECT, 2021
** DISPLAY MANAGER
** File description:
** display
*/

#include "./include/mysh.h"

char *get_last(char **array)
{
    int i = 0;
    for (; array[i] != NULL; i++);
    return array[i-1];
}

void free_array(char ***array)
{
    for (int i = 0; (*array)[i] != NULL; i++) {
        free((*array)[i]);
    }
    free((*array));
};

int get_cmd(char **cmd, mysh_t *mysh)
{
    size_t t = 0;

    mysh = mysh;
    if (isatty(0))
        my_printf("$> ");
    return (getline(cmd, &t, stdin));
}
