/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:06:50 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:06:52 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static t_data	*g_ptr_data;

void	ft_init_ptr(t_data *data)
{
	g_ptr_data = data;
}

void	ft_sigint_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_free_garbage_collector(g_ptr_data);
		ft_printf("\n");
		exit(130);
	}
}

void	ft_handle_heredoc_signal(void)
{
	signal(SIGINT, &ft_sigint_heredoc);
}

void	ft_handle_ctrld_heredoc(t_data *data, char *end)
{
	ft_printf("minishell: warning : here-document");
	ft_printf("delimited by end_of_file (wanted `%s')\n", end);
	ft_exit(data);
}

void	ft_handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_ptr_data->last_pipeline_exit_status = 130;
	}
}
