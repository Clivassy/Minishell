/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:11:35 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:11:38 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_dup_env(t_data *data, char **envp)
{
	int	i;

	data->env = ft_malloc(data, sizeof(char *)
			* (ft_env_nb_of_lines(envp) + 1));
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
}
