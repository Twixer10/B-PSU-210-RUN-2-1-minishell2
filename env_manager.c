/*
** EPITECH PROJECT, 2021
** ENVIRONEMENT MANAGER
** File description:
** NO DESC FOUND
*/

#include "./include/mysh.h"

char *my_newstrcpy(char *str)
{
    int idx = 0;
    char *new_str;

    while (str && str[idx])
        idx += 1;
    if (!(new_str = malloc(sizeof(char) * idx + 1)))
        return (NULL);
    idx = 0;
    while (str[idx] != '\0') {
        new_str[idx] = str[idx];
        idx += 1;
        }
    new_str[idx] = '\0';
    return (new_str);
}

char **envcpy(char **env)
{
    int idx_line = 0;
    char **env_cpy;

    while (env != NULL && env[idx_line])
        idx_line += 1;
    if ((env_cpy = malloc(sizeof(char *) * (idx_line + 1))) == NULL)
        my_exit(84, "ERROR: Out of memory ! [001]\n");
    idx_line = 0;
    while (env != NULL && env[idx_line]) {
        env_cpy[idx_line] = my_newstrcpy(env[idx_line]);
        idx_line += 1;
    }
    env_cpy[idx_line] = NULL;
    return (env_cpy);
}

char **envcpyforrm(char **env, char *rm)
{
    int idx_line = 0;
    int idx_bis = 0;
    char **env_cpy;

    if (my_getenv(env, rm)) {
        while (env != NULL && env[idx_line])
            idx_line += 1;
        if ((env_cpy = malloc(sizeof(char *) * (idx_line))) == NULL)
            my_exit(84, "ERROR: Out of memory ! [001]\n");
        idx_line = 0;
        while (env != NULL && env[idx_bis]) {
            if (my_strncmp(env[idx_bis], rm, my_strlen(rm)) != 0)
                env_cpy[idx_line++] = my_newstrcpy(env[idx_bis]);
            idx_bis += 1;
        }
        env_cpy[idx_line] = NULL;
        return (env_cpy);
    }
    return (env);
}

char *my_getenv(char **env, const char *to_find)
{
    int idx = 0;
    char *elem = NULL;

    while (env != NULL && env[idx]) {
        if (!my_strncmp(env[idx], to_find, my_strlen(to_find)))
            elem = env[idx];
        idx += 1;
    }
    return ((elem != NULL ? my_strtok(elem, '=')[1] : NULL));
}

void show_env(char **env)
{
    int idx = 0;

    while (env != NULL && env[idx]) {
        my_printf("%s\n", env[idx]);
        idx += 1;
    }
    return ;
}