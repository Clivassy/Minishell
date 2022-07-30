/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:10:24 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:10:27 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_builtin_cd(t_data *data, char **cmd)
{
	int	error_status;

	if (ft_null_terminated_tab_len(cmd) < 2)
		return (ft_cd_error_no_arg(data));
	if (ft_null_terminated_tab_len(cmd) > 2)
		return (ft_cd_error_too_many_arg(data));
	error_status = chdir(cmd[1]);
	if (error_status != 0)
	{
		return (ft_cd_error_no_dir(data, cmd[1]));
	}
	else
	{
		return (0);
	}
}
