/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-thomas.techer
** File description:
** command_manager2
*/

#include "./include/mysh.h"

int check_exe(char *exe, char **cmd)
{
    if (exe == NULL || access(exe, F_OK) == -1) {
        free(exe);
        my_printf("%s: Command not found.\n", cmd[0]);
        return (FALSE);
    }
    if (access(exe, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", exe);
        free(exe);
        return (FALSE);
    }
    return (TRUE);
}

int signal_handler(int sigint_behavior)
{
    if (sigint_behavior == SIGINT_IGNORE)
        if (signal(SIGINT, SIG_IGN) == SIG_ERR)
            my_printf("ERROR: Can't initiate signal handler.\n");
    if (signal(SIGTERM, SIG_IGN) == SIG_ERR ||
    signal(SIGQUIT, SIG_IGN) == SIG_ERR ||
    signal(SIGTSTP, SIG_IGN) == SIG_ERR ||
    signal(SIGTTIN, SIG_IGN) == SIG_ERR ||
    signal(SIGTTOU, SIG_IGN) == SIG_ERR)
        my_printf("ERROR: Can't initiate signal handler.\n");
    return (-1);
}

void parent_exec(pid_t pid, int *status)
{
    signal_handler(SIGINT_IGNORE);
    waitpid(pid, status, WUNTRACED);
    if (*status == 136)
        write(2, "Floating exception (core dumped)\n", 33);
    else if (*status == 139)
        write(2, "Segmentation fault (core dumped)\n", 33);
    return;
}
