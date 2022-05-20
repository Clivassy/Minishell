#include "minishell.h"

static int nb_of_env_lines(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    return (i);
}

void    dup_env(t_data *data, char **envp)
{
    int i;

    data->env = malloc(sizeof(char *) * nb_of_env_lines(envp) + 1);
    printf("nb lines = %d\n", nb_of_env_lines(envp));
    i = 0;
    while (i < nb_of_env_lines(envp) + 1)
    {
        data->env[i] = NULL;
        i++;
    }
    i = 0;
    while (envp[i])
    {
        data->env[i] = ft_strdup((const char *)envp[i]);
        i++;
    }
    print_env(data->env);
}