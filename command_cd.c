/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-thomas.techer
** File description:
** command_cd
*/

#include "./include/mysh.h"

void update_env(char ***env, char *oldpwd)
{
    char *pwd;

    if ((pwd = malloc(sizeof(char) * 4096)) == NULL)
        my_exit(EXIT_FAILURE, "ERROR: Out of memory! [006]\n");
    if (getcwd(pwd, 100) == NULL)
        my_exit(EXIT_FAILURE, "ERROR: Can't get getcwd ! [007].");
    if (my_strcmp(pwd, oldpwd) == FALSE)
        my_setenv(env, "OLDPWD=", oldpwd);
    my_setenv(env, "PWD=", pwd);
    free(pwd);
    return;
}

int handle_oldpwd(char **env)
{
    int ret = EXIT_SUCCESS;
    char *oldpwd_var;

    oldpwd_var = my_getenv(env, "OLDPWD=");
    if (oldpwd_var == NULL) {
        write(2, ": No such file or directory.\n", 29);
        ret = EXIT_FAILURE;
    } else if (chdir(oldpwd_var) == -1) {
        my_printf_err("%s: No such file or directory.\n",
        my_getenv(env, "OLDPWD="));
        ret = EXIT_FAILURE;
    }
    return (ret);
}

int switch_to_dir(char *dir)
{
    if (chdir(dir) == -1) {
        my_printf_err("%s: No such file or directory.\n", dir);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int command_cd(char ***env, char **argv)
{
    int ret;
    char *homedir;
    char *oldpwd;

    if ((oldpwd = malloc(sizeof(char) * 4096)) == NULL)
        my_exit(EXIT_FAILURE, "ERROR: Out of memory! Please reduce 4096.\n");
    ret = EXIT_FAILURE;
    if (getcwd(oldpwd, 100) == NULL)
        my_exit(EXIT_FAILURE, "ERROR: getcwd() failed.");
    if (argv[1] == NULL) {
        if ((homedir = my_getenv(*env, "HOME=")) == NULL || homedir[0] == '\0')
            write(2, "cd: No home directory.\n", 23);
        else
            ret = switch_to_dir(homedir);
    } else if (argv[1][0] == '-')
        ret = handle_oldpwd(*env);
    else
        ret = switch_to_dir(argv[1]);
    update_env(env, oldpwd);
    free(oldpwd);
    return (ret);
}
