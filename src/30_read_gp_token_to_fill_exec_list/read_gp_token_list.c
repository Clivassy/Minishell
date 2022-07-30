/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_gp_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:50 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:08:53 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	ft_token_is_redirect(int type)
{
	if (type == T_REDIRECT_IN
		|| type == T_REDIRECT_OUT
		|| type == D_REDIRECT_OUT)
	{
		return (1);
	}
	return (0);
}

void	ft_fill_exec_list_cmd__and_redirect(t_data *data)
{
	int			process;
	t_token		*pt_token;
	t_exec_elm	*exec_elm;

	process = 0;
	pt_token = data->gp_tokens_list;
	while (pt_token)
	{
		if (pt_token->type == T_PIPE)
			process++;
		exec_elm = ft_get_exec_elm(data->exec_list, process);
		if (pt_token->type == T_HEREDOC)
			ft_set_exec_with_t_heredoc(data, pt_token, process);
		if (exec_elm->has_redirect_pb != 1)
		{
			if (pt_token->type == T_CMD)
				ft_set_exec_with_t_cmd_token(data, pt_token, process);
			else if (ft_token_is_redirect(pt_token->type))
			{
				if (ft_set_exec_t_redirect_token(data, pt_token, process) == 1)
					exec_elm->has_redirect_pb = 1;
			}
		}
		pt_token = pt_token->next;
	}
}

void	ft_build_exec_list(t_data *data)
{
	ft_create_exec_elm_list(data);
	ft_fill_exec_list_cmd__and_redirect(data);
}
