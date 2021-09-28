/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-thomas.techer
** File description:
** pipe_manager2
*/

#include "./include/mysh.h"

void wait_status(int i, int fd[2], int in, int out)
{
    int status = 0;

    for (; i >= 0; i--) {
        wait(&status);
        if (status == 136)
            write(2, "Floating exception (core dumped)\n", 33);
        else if (status == 139)
            write(2, "Segmentation fault (core dumped)\n", 33);
    }
    close_dup(fd, in, out);
}

void close_dup(int fd[2], int in, int out)
{
    close(fd[0]);
    close(fd[1]);
    duplicate(in, out);
}

void duplicate(int in, int out)
{
    dup2(in, 0);
    dup2(out, 1);
    close(in);
    close(out);
}