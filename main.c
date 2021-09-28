/*
** EPITECH PROJECT, 2021
** MY SH
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/mysh.h"

int main(int ac, char **av, char **env)
{
    mysh_t *mysh = malloc(sizeof(mysh_t));
    ac = ac;
    av = av;
    char *cmd = NULL;
    char **tmp = NULL;

    mysh->env = envcpy(env);
    while (get_cmd(&cmd, mysh) != -1) {
        tmp = my_strtok(cmd, ';');
        for (int i = 0; tmp[i]; i++) {
            command_manager(mysh, clean_str(tmp[i]));
            free(tmp[i]);
        }
        free(tmp);
    }
    free(cmd);
    free_obj(mysh);
    if (isatty(0))
        my_printf("exit\n");
    return (0);
}