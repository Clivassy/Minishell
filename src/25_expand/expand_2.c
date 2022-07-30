/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:07:27 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:07:31 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_key_size_for_expand(t_data *data, char *str)
{
	int	i;

	(void)data;
	i = 0;
	while (str[i] != ' ' && str[i] != '$' && str[i] != '\''
		&& str[i] != '\"' && str[i])
		i++;
	return (i);
}

char	*ft_get_key_for_expand(t_data *data, char *str)
{
	int		i;
	int		key_size;
	char	*key;

	key_size = ft_key_size_for_expand(data, str);
	key = ft_malloc(data, sizeof(char) * (key_size + 1));
	if (!key)
		ft_exit(data);
	i = 0;
	while (i < key_size)
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

// ancienne ligne apres ftadd_to_str
// *i += ft_strlen(tmp);
void	ft_expand_pipeline_exit_status(t_data *data, char **str, int *i)
{
	char	*tmp;

	ft_rm_from_str(data, str, 2, *i);
	tmp = ft_itoa(data->last_pipeline_exit_status);
	if (!tmp)
		ft_exit(data);
	ft_add_to_str(data, str, tmp, *i);
	free(tmp);
	tmp = NULL;
}

void	ft_expand_normal_key(t_data *data, char **str, int *i)
{
	char	*key;

	key = ft_get_key_for_expand(data, &(*str)[*i + 1]);
	if (ft_env_key_is_present(data, key))
	{
		ft_rm_from_str(data, str, ft_strlen(key) + 1, *i);
		ft_add_to_str(data, str, ft_env_get_value(data, key), *i);
		*i += ft_strlen(ft_env_get_value(data, key));
		(*i)--;
	}
	else
	{
		ft_rm_from_str(data, str, ft_strlen(key) + 1, *i);
		(*i)--;
	}
	ft_free(data, key);
}

int	ft_is_next_word_to_expand(t_token *token)
{
	if (token->type == T_PIPE
		|| token->type == T_REDIRECT_IN
		|| token->type == T_REDIRECT_OUT
		|| token->type == D_REDIRECT_OUT
		|| token->type == D_QUOTE
		|| token->type == S_QUOTE
		|| token->type == T_WORD)
	{
		return (1);
	}
	else if (token->type == T_HEREDOC)
	{
		return (0);
	}
	else
	{
		ft_printf("erreur dans l'expand, le type du token est invalide\n");
		return (0);
	}
}
