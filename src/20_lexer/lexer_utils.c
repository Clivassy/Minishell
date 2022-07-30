/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:04:20 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:04:23 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_is_space_sep(char c)
{
	if (c == '\t' || c == '\v'
		|| c == '\n' || c == '\r'
		|| c == '\f' || c == '\r'
		|| c == ' ')
		return (0);
	return (1);
}

void	ft_fill_new_token(char *content, t_data *data, int type)
{
	t_token	*new_token;

	new_token = ft_new_token(data, content, type);
	ft_lstadd_back_token(&data->tokens_list, new_token);
}

/* Return 1 if readline token is a word (if no metachracters are found) */
int	ft_is_word(char *line, int index)
{
	if (line[index] == '<' || line[index] == '>'
		|| line[index] == '|'
		|| ft_is_space_sep(line[index]) == 0)
		return (0);
	return (1);
}

int	ft_check_unclose_quote(char	*line)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			if (quote == 0)
				quote = D_QUOTE;
			else if (quote == D_QUOTE)
				quote = 0;
		}
		if (line[i] == '\'')
		{
			if (quote == 0)
				quote = S_QUOTE;
			else if (quote == S_QUOTE)
				quote = 0;
		}
		i++;
	}
	return (quote);
}
