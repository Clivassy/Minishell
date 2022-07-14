#include "minishell.h"

/* fait expand sur la value d'un token */
void	ft_expand_token(t_data *data, t_token *token)
{
	int		i;
	char	*key;
	int		expand_active;

	i = 0;
	expand_active = 1;
	while (token->value[i])
	{
		if (token->value[i] == '\'')
			expand_active = 1 - expand_active;
		if (token->value[i] == '$' && expand_active)
		{
			if (token->value[i + 1] == '?')
				ft_expand_pipeline_exit_status(data, &token->value, &i);
			else
				ft_expand_normal_key(data, &token->value, &i);
		}
		i++;
	}
}

void	ft_expand(t_data *data)
{
	t_token	*token;
	int		next_word_to_expand;

	token = data->tokens_list;
	next_word_to_expand = 1;
	while (token)
	{
		if (next_word_to_expand && token->type == T_WORD)
			ft_expand_token(data, token);
		if (token->type != T_SPACE)
			next_word_to_expand = ft_is_next_word_to_expand(token);
		token = token->next;
	}
}

/* fait expand sur str */
void	ft_expand_str(t_data *data, char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			if ((*str)[i + 1] == '?')
				ft_expand_pipeline_exit_status(data, str, &i);
			else
				ft_expand_normal_key(data, str, &i);
		}
		i++;
	}
}
