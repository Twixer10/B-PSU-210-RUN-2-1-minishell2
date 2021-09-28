/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-thomas.techer
** File description:
** command_manager
*/

#include "./include/mysh.h"

char exe(char *exec_path, char **cmd, mysh_t *mysh, int ispipe)
{
    pid_t pid;
    int status = 0;

    if (ispipe == 1) {
        execve(exec_path, cmd, mysh->env);
        return (' ');
    }
    if ((pid = fork()) == -1)
        my_printf("ERROR: Failed to run child process!\n");
    if (pid == 0) {
        if ((execve(exec_path, cmd, mysh->env) == -1))
            my_printf("%s: Permission denied.\n", exec_path);
    } else
        parent_exec(pid, &status);
    signal_handler(SIGINT_REGULAR);
    free(exec_path);
    return (WEXITSTATUS(status));
}

char **get_path(mysh_t *mysh)
{
    if (my_getenv(mysh->env, "PATH=") == NULL)
        return (NULL);
    if (my_strcmp(my_getenv(mysh->env, "PATH="), ""))
        return (NULL);
    else {
        return (my_strtok(my_getenv(mysh->env, "PATH="), ':'));
    }
}

void execute_other_command(mysh_t *mysh, char **cmd, int ispipe) {
    char **path = get_path(mysh);
    char *tmp = NULL;

    if (access(cmd[0], F_OK) == -1) {
        if (path == NULL)
            tmp = my_strcat("/usr/bin/", cmd[0]);
        else
            for (int i = 0; path[i]; i++) {
                tmp = my_strcat(path[i], "/");
                tmp = my_strcat(tmp, cmd[0]);
                if (tmp != NULL && (tmp[0] == '/' && tmp[0] != '.')
                && access(tmp, F_OK) != -1)
                    break;
            }
    } else
        tmp = cmd[0];
    if (check_exe(tmp, cmd))
        exe(tmp, cmd, mysh, ispipe);
}

void other(mysh_t *mysh, char **cmd, char *str)
{
    if (!my_strcmp(cmd[0], "env") && !my_strcmp(cmd[0], "exit") &&
    !my_strcmp(cmd[0], "cd") &&
    !my_strcmp(cmd[0], "setenv") && !my_strcmp(cmd[0], "unsetenv")) {
        if (!str_contains(str, "|")) {
            execute_other_command(mysh, cmd, 0);
            for (int i = 0; cmd[i]; i++)
                free(cmd[i]);
            free(cmd);
        } else
            execute_pipe_cmd(mysh, str);
    }
}

void command_manager(mysh_t *mysh, char *str)
{
    char **cmd;

    if (my_strcmp(clean_str(str), ""))
        return;
    cmd = my_strtok(str, ' ');
    if (my_strcmp(cmd[0], "env") == TRUE)
        return (show_env(mysh->env));
    if (my_strcmp(cmd[0], "setenv") == TRUE)
        run_setenv(&mysh->env, cmd);
    if (my_strcmp(cmd[0], "unsetenv") == TRUE)
        my_unsetenv(mysh, cmd);
    if (my_strcmp(cmd[0], "exit") == TRUE)
        free_exit(mysh, cmd);
    if (my_strcmp(cmd[0], "cd") == TRUE) {
        if (array_len(cmd) <= 2)
            command_cd(&mysh->env, cmd);
        else
            my_printf("cd: too many arguments\n");
    }
    other(mysh, cmd, str);
}