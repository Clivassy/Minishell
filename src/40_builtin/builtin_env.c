/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:10:37 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:10:39 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_builtin_env(t_data *data, char **cmd)
{
	char	**env;

	(void)cmd;
	env = data->env;
	if (!env)
		return (0);
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
	return (0);
}
