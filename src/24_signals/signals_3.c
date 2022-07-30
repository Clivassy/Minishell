/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:06:58 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:07:04 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_handle_ctrld(t_data *data)
{
	write(1, "exit\n", 6);
	ft_exit(data);
}

void	ft_handle_sigquit(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_handle_signals(void)
{
	signal(SIGINT, &ft_handle_sigint);
	signal(SIGQUIT, &ft_handle_sigquit);
}
