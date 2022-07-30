/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_redirection_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:57 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:09:01 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process)
{
	int	fd_infile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_infile = open(token->value, O_RDONLY);
	if (fd_infile < 0)
	{
		ft_print_open_error(data, token->value);
		return (1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
	{
		if (close(ft_get_exec_elm(data->exec_list, process)->fd_in) == -1)
			ft_exit_close_error(data);
	}
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_infile;
	return (0);
}

int	ft_set_exec_t_redirect_out(t_data *data, t_token *token, int process)
{
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
	{
		ft_print_open_error(data, token->value);
		return (1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
	{
		if (close(ft_get_exec_elm(data->exec_list, process)->fd_out) == -1)
			ft_exit_close_error(data);
	}
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
	return (0);
}

int	ft_set_exec_d_redirect_out(t_data *data, t_token *token, int process)
{
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd_outfile < 0)
	{
		ft_print_open_error(data, token->value);
		return (1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
	{
		if (close(ft_get_exec_elm(data->exec_list, process)->fd_out) == -1)
			ft_exit_close_error(data);
	}
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
	return (0);
}

int	ft_set_exec_t_redirect_token(t_data *data, t_token *token, int process)
{
	if (token->type == T_REDIRECT_IN)
	{
		if (ft_set_exec_t_redirect_in(data, token, process) == 1)
		{
			return (1);
		}
	}
	else if (token->type == T_REDIRECT_OUT)
	{
		if (ft_set_exec_t_redirect_out(data, token, process) == 1)
		{
			return (1);
		}
	}
	else if (token->type == D_REDIRECT_OUT)
	{
		if (ft_set_exec_d_redirect_out(data, token, process) == 1)
		{
			return (1);
		}
	}
	return (0);
}
