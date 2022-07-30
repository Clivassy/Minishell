/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:09:06 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:09:11 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	ft_cmd_len(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		i++;
	}
	return (i);
}

void	ft_set_exec_with_t_cmd_token(t_data *data, t_token *token, int process)
{
	t_exec_elm	*current_exec_elm;
	char		**cmd_lst;
	char		**new_command;
	int			i;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	current_exec_elm = ft_get_exec_elm(data->exec_list, process);
	cmd_lst = ft_get_exec_elm(data->exec_list, process)->cmd;
	new_command = ft_malloc(data, sizeof(char *) * (ft_cmd_len(cmd_lst) + 2));
	i = 0;
	while ((cmd_lst)[i])
	{
		new_command[i] = cmd_lst[i];
		i++;
	}
	new_command[i] = token->value;
	new_command[i + 1] = NULL;
	ft_free(data, cmd_lst);
	ft_get_exec_elm(data->exec_list, process)->cmd = new_command;
}
