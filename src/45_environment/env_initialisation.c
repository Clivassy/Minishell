/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:42:18 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/08 00:32:21 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_dup_env(t_data *data, char **envp)
{
    int i;

    data->env = malloc(sizeof(char *) * ft_env_nb_of_lines(envp) + 1);
    printf("nb lines = %d\n", ft_env_nb_of_lines(envp));
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
        i++;
    }
    print_env(data->env);
}

