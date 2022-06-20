#include "minishell.h"

int	ft_key_size_for_expand(t_data *data, char *str)
{
	int	i;

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

	//if (*str == '?')
	//{
	//	key = ft_strdup("?");
	//	if (!key)
	//		ft_exit(data);
	//	ft_add_to_garbage_collector(data, key);
	//	return (key);
	//}
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

void	ft_expand_token(t_data *data, t_token *token)
{
	int		i;
	char	*key;
	int		expand_active;
	char *tmp;

	i = 0;
	expand_active = 1;
	while (token->value[i])
	{
		if (token->value[i] == '\'')
			expand_active = 1 - expand_active;
		if (token->value[i] == '$')
		{
			key = ft_get_key_for_expand(data, &token->value[i + 1]);
			if (token->value[i+1] == '?' && expand_active)
			{
				ft_rm_from_str(data, &(token->value), 2, i);
				tmp = ft_itoa(data->last_pipeline_exit_status);
				if (!tmp)
					ft_exit(data);
				ft_add_to_str(data, &(token->value),tmp, i);
				i += strlen(tmp);
				free(tmp);
				tmp = NULL;
			}
			else if (ft_env_key_is_present(data, key) && expand_active)
			{
				ft_rm_from_str(data, &(token->value), strlen(key) + 1, i);
				ft_add_to_str(data, &(token->value),
					ft_env_get_value(data, key), i);
				i += strlen(ft_env_get_value(data, key));
			}
			else if (expand_active)
				ft_rm_from_str(data, &(token->value), strlen(key) + 1, i);
			ft_free(data, key);
		}
		i++;
	}
}

// fct non testee
static int	ft_is_next_word_to_expand(t_token *token)
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

// possible d'enlever la prise en compte des here doc ?
// car ils sont fait avant cette etape
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
