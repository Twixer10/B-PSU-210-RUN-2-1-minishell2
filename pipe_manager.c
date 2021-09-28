/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-thomas.techer
** File description:
** pipe_manager
*/

#include "./include/mysh.h"

void execute_pipe_cmd(mysh_t *sh, char *pipecmd)
{
    char **pipe = my_strtok(pipecmd, '|');
    int default_t = 0;
    int in = dup(0);
    int out = dup(1);
    int i = 0;
    int fd[2];
    char **cmd = NULL;

    for (i = 0; pipe[i];) {
        cmd = my_strtok(pipe[i], ' ');
        pid_t pid = get_pid(fd);
        if (pid == 0)
            exepipe(default_t, pipe, i, fd, cmd, sh);
        else {
            close(fd[1]);
            default_t = fd[0];
            i++;
        }
    }
    wait_status(i, fd, in, out);
}

pid_t get_pid(int fd[2])
{
    pid_t pid;

    if (pipe(fd) == -1)
        exit(1);
    pid = fork();
    if (pid == -1)
        exit(1);
    return (pid);
}

void exepipe(int d, char **pipe, int i, int fd[2], char **cmd, mysh_t *sh)
{
    dup2(d, 0);
    if (pipe[i + 1] != NULL)
        dup2(fd[1], 1);
    close(fd[0]);
    execute_other_command(sh, cmd, 1);
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
    for (int i = 0; pipe[i]; i++)
        free(pipe[i]);
    free(pipe);
    exit(1);
}
