/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-thomas.techer
** File description:
** env_manager3
*/

#include "./include/mysh.h"

int run_setenv(char ***env, char **cmd)
{
    char *tmp;

    if (array_len(cmd) < 2) {
        show_env(*env);
        return (0);
    } else if (array_len(cmd) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    if ((tmp = malloc(sizeof(char) * (my_strlen(cmd[1]) + 2))) == NULL)
        my_printf("ERROR: Out of memory! [009]\n");
    tmp = my_strncpy(tmp, cmd[1], my_strlen(cmd[1]));
    tmp = my_strncat(tmp, "=", 1);
    my_setenv(env, tmp, (cmd[2]?cmd[2]:NULL));
    free(tmp);
    return (0);
}