/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:06:41 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:06:44 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_handle_exec_sigquit(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_handle_exec_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		exit(130);
	}
}

void	ft_handle_exec_signal(void)
{
	signal(SIGINT, &ft_handle_exec_sigint);
}
