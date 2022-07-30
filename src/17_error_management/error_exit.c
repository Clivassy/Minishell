/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:02:28 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:02:30 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_print_exit_error_too_many_arg(t_data *data)
{
	(void)data;
	write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
	return (1);
}

int	ft_exit_print_error_not_numeric_arg(t_data *data, char *arg)
{
	(void)data;
	write(STDERR_FILENO, "minishell: exit: ", ft_strlen("minishell: exit: "));
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, ": numeric argument required\n",
		ft_strlen(": numeric argument required\n"));
	return (2);
}
