/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-thomas.techer
** File description:
** utils2
*/

#include "./include/mysh.h"

void free_exit(mysh_t *sh, char **cmd)
{
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
    for (int i = 0; sh->env[i]; i++)
        free(sh->env[i]);
    free(sh->env);
    free(sh);
    exit(0);
}

void free_obj(mysh_t *sh)
{
    for (int i = 0; sh->env[i]; i++)
        free(sh->env[i]);
    free(sh->env);
    free(sh);
}

void my_exit(int erroc_code, char *error_message)
{
    my_putstr(error_message);
    exit(erroc_code);
}