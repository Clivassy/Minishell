/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:10:43 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:10:46 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ft_is_number(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_builtin_exit(t_data *data, char **cmd)
{
	int	return_statut;

	if (data->nb_of_process == 1)
		write(2, "exit\n", 5);
	if (ft_null_terminated_tab_len(cmd) == 1)
		ft_exit2(data, 0);
	if (ft_null_terminated_tab_len(cmd) == 2)
	{
		if (!ft_is_number(cmd[1]))
			return_statut = ft_exit_print_error_not_numeric_arg(data, cmd[1]);
		else
			return_statut = ft_atoi(cmd[1]);
		ft_exit2(data, return_statut);
	}
	else
	{
		if (!ft_is_number(cmd[1]))
			ft_exit2(data, ft_exit_print_error_not_numeric_arg(data, cmd[1]));
		else
			return (ft_print_exit_error_too_many_arg(data));
	}
	ft_exit2(data, 1);
	return (1);
}
