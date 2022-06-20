#include "minishell.h"

void    ft_dup_env(t_data *data, char **envp)
{
    int i;

    data->env = ft_malloc(data, sizeof(char *) * (ft_env_nb_of_lines(envp) + 1));
    //printf("nb lines = %d\n", ft_env_nb_of_lines(envp));
    i = 0;
    while (i < ft_env_nb_of_lines(envp) + 1)
    {
        data->env[i] = NULL;
        i++;
    }
    i = 0;
    while (envp[i])
    {
        data->env[i] = ft_strdup((const char *)envp[i]);
		ft_add_to_garbage_collector(data, data->env[i]);
        i++;
    }
    //print_env(data->env);
}

