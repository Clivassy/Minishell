#include "minishell.h"

static int	ft_key_size_for_expand(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '$' && str[i] != '\''
		&& str[i] != '\"' && str[i])
		i++;
	return (i);
}

static char	*ft_get_key_for_expand(t_data *data, char *str)
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

// extand pour '$?'
static void	ft_expand_pipeline_exit_status(t_data *data, char **str, int *i)
{
	char	*tmp;

	ft_rm_from_str(data, str, 2, *i);
	tmp = ft_itoa(data->last_pipeline_exit_status);
	if (!tmp)
		ft_exit(data);
	ft_add_to_str(data, str, tmp, *i);
	*i += strlen(tmp);
	free(tmp);
	tmp = NULL;
}

// i-- utiliser car apres rm on se retrouve sur le char suivant qui sera
// saute dans la boucle qui appelle cette fonction
static void	ft_expand_normal_key(t_data *data, char **str, int *i)
{
	char	*key;

	key = ft_get_key_for_expand(data, &(*str)[*i + 1]);
	if (ft_env_key_is_present(data, key))
	{
		ft_rm_from_str(data, str, strlen(key) + 1, *i);
		ft_add_to_str(data, str, ft_env_get_value(data, key), *i);
		*i += strlen(ft_env_get_value(data, key));
		(*i)--;
	}
	else
	{
		ft_rm_from_str(data, str, strlen(key) + 1, *i);
		(*i)--;
	}
	ft_free(data, key);
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

// a changer par une fonction qui prend un char *
void	ft_expand_token(t_data *data, t_token *token)
{
	int		i;
	char	*key;
	int		expand_active;

	i = 0;
	expand_active = 1;
	while (token->value[i])
	{
		//printf("i:%d token->value[i]:%c\n", i, token->value[i]);
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

// void	ft_expand_word(t_data *data, char *word)
// {
// 	int		i;
// 	char	*key;
// 	int		expand_active;

// 	i = 0;
// 	expand_active = 1;
// 	while (word[i])
// 	{
// 		//printf("i:%d token->value[i]:%c\n", i, token->value[i]);
// 		if (word[i] == '\'')
// 			expand_active = 1 - expand_active;
// 		if (word[i] == '$' && expand_active)
// 		{
// 			if (word[i + 1] == '?')
// 				ft_expand_pipeline_exit_status(data, &word, &i);
// 			else
// 				ft_expand_normal_key(data, &word, &i);
// 		}
// 		i++;
// 	}
// }

// fonction qui va expand les token autres que heredoc
// mais fonction codee avant ajout de la liste gp_token
// ne pas l'utiliser comme ca
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
