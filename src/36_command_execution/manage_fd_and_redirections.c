/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fd_and_redirections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:10:09 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:10:12 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_save_stdin_out(t_data *data)
{
	data->fd_save_stdin = dup(STDIN_FILENO);
	if (data->fd_save_stdin == -1)
		ft_exit_dup_error(data);
	data->fd_save_stdout = dup(STDOUT_FILENO);
	if (data->fd_save_stdout == -1)
		ft_exit_dup_error(data);
}

// restore stdin stdout and close the saves
void	ft_restore_stdin_out(t_data *data)
{
	if (dup2(data->fd_save_stdin, STDIN_FILENO) == -1)
		ft_exit_dup_error(data);
	if (dup2(data->fd_save_stdout, STDOUT_FILENO) == -1)
		ft_exit_dup_error(data);
	if (close(data->fd_save_stdin) == -1)
		ft_exit_close_error(data);
	data->fd_save_stdin = -1;
	if (close(data->fd_save_stdout) == -1)
		ft_exit_close_error(data);
	data->fd_save_stdout = -1;
}

void	ft_make_fd_redirection(t_data *data, t_exec_elm *exec_elm)
{
	if (exec_elm->fd_in != STDIN_FILENO)
	{
		if (dup2(exec_elm->fd_in, STDIN_FILENO) == -1)
			ft_exit_dup_error(data);
		if (close(exec_elm->fd_in) == -1)
			ft_exit_close_error(data);
		exec_elm->fd_in = -1;
	}
	if (exec_elm->fd_out != STDOUT_FILENO)
	{
		if (dup2(exec_elm->fd_out, STDOUT_FILENO) == -1)
			ft_exit_dup_error(data);
		if (close(exec_elm->fd_out) == -1)
			ft_exit_close_error(data);
		exec_elm->fd_out = -1;
	}
}
