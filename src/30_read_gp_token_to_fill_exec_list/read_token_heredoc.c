/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:09:16 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:09:20 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_set_exec_with_t_heredoc(t_data *data, t_token *token, int process)
{
	t_fd_heredoc	*fd_heredoc;

	(void)token;
	fd_heredoc = ft_pop_first_fd_lst(data);
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_heredoc->fd;
	ft_free(data, fd_heredoc);
}
