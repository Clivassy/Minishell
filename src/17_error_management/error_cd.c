/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:01:32 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:01:35 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_cd_error_too_many_arg(t_data *data)
{
	(void)data;
	write(STDERR_FILENO, "minishell: cd: too many arguments\n", 34);
	return (1);
}

int	ft_cd_error_no_arg(t_data *data)
{
	(void)data;
	write(STDERR_FILENO, "minishell: cd: no argument\n", 27);
	return (1);
}

int	ft_cd_error_no_dir(t_data *data, char *cmd)
{
	(void)data;
	write(STDERR_FILENO, "minishell: cd: ", ft_strlen("minishell: cd: "));
	write(STDERR_FILENO, "cmd", ft_strlen(cmd));
	write(STDERR_FILENO, ": No such file or directory\n",
		ft_strlen(": No such file or directory\n"));
	return (1);
}
