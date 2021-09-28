/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-thomas.techer
** File description:
** env_manager2
*/

#include "./include/mysh.h"

char *get_new_env_line(char *to_change, char *new_value)
{
    char *new_env_line;

    new_env_line = malloc(sizeof(char) * (my_strlen(to_change)
    + (new_value == NULL ? 0:my_strlen(new_value)) + 1));
    if (new_env_line == NULL)
        my_exit(84, "ERROR: Out of memory! [002]\n");
    new_env_line = my_strncpy(new_env_line, to_change, my_strlen(to_change));
    if (new_value != NULL)
        new_env_line = my_strncat(new_env_line,
        new_value, my_strlen(new_value));
    return (new_env_line);
}

char **add_var(char **env, char *to_change, char *new_v,
int env_size)
{
    int idx = 0;
    char **new_env;

    if ((new_env = malloc(sizeof(char *) * (env_size + 2))) == NULL)
        my_exit(EXIT_FAILURE, "ERROR: Out of memory! [003]\n");
    while (env != NULL && env[idx]) {
        new_env[idx] = env[idx];
        idx += 1;
    }
    new_env[idx] = malloc(sizeof(char) * (my_strlen(to_change)
    + (new_v == NULL ? 0:my_strlen(new_v)) + 1));
    if (new_env[idx] == NULL)
        my_exit(EXIT_FAILURE, "ERROR: Out of memory! [004]\n");
    new_env[idx] = my_strncpy(new_env[idx], to_change, my_strlen(to_change));
    if (new_v != NULL)
        new_env[idx] = my_strncat(new_env[idx], new_v, my_strlen(new_v));
    idx += 1;
    new_env[idx] = NULL;
    free(env);
    return (new_env);
}

void my_setenv(char ***env, char *to_change, char *new_value)
{
    int    idx = 0;
    char *tmp;
    char **new_env = *env;

    while (new_env != NULL && new_env[idx]) {
        if (my_strncmp(new_env[idx], to_change, my_strlen(to_change)) == 0) {
            tmp = get_new_env_line(to_change, new_value);
            free(new_env[idx]);
            new_env[idx] = my_newstrcpy(tmp);
            free(tmp);
            return;
    }
            idx += 1;
        }
    *env = add_var(new_env, to_change, new_value, idx);
    return;
}

int get_var_pos(char **env, char *to_unset)
{
    int pos = 0;

    while (env != NULL && env[pos]) {
        if (my_strncmp(env[pos], to_unset, my_strlen(to_unset)) == 0)
            return (pos);
        pos += 1;
    }
    return (pos);
}

void my_unsetenv(mysh_t *sh, char **to_unset)
{
    for (int i = 1; to_unset[i]; i++) {
        sh->env = envcpyforrm(sh->env, to_unset[i]);
    }
}
