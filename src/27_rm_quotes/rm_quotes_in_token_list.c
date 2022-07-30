/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_in_token_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:07:54 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:07:57 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	manage_open_d_quote(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '"')
	{
		ft_rm_from_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

int	manage_open_s_quote(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '\'')
	{
		ft_rm_from_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

int	manage_close_d_quote(t_data *data, char **str, int *i)
{
	ft_rm_from_str(data, str, 1, *i);
	(*i)--;
	return (1);
}

int	manage_close_s_quote(t_data *data, char **str, int *i)
{
	ft_rm_from_str(data, str, 1, *i);
	(*i)--;
	return (1);
}

void	ft_rm_quotes_in_tokens_list(t_data *data)
{
	t_token	*token;

	token = data->tokens_list;
	while (token)
	{
		ft_rm_quotes_in_token(data, token);
		token = token->next;
	}
}
