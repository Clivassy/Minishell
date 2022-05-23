/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:26 by ybellot           #+#    #+#             */
/*   Updated: 2022/05/23 17:19:27 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
