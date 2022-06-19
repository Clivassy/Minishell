#include "minishell.h"

int	ft_key_size_for_expand(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '$' && str[i])
		i++;
	return (i);
}

char	*ft_get_key_for_expand(t_data *data, char *str)
{
	//printf("debug\n");
	//printf("input get key : %s\n", str);
	int	i;
	int key_size;
	char *key;
	key_size = ft_key_size_for_expand(data, str);
	//printf("keysize : %d\n", key_size);

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

//a completer avec la gestion de expand active
void	ft_expand_token(t_data *data, t_token *token)
{
	int		i;
	char	*key;
	int		expand_active;

	//str = token->value;
	i = 0;
	expand_active = 1;
	while (token->value[i])
	{
		//printf("lettre lu : %c\n", token->value[i]);
		if (token->value[i] == '\'')
			expand_active = 1 - expand_active;
		if (token->value[i] == '$')
		{

		key = ft_get_key_for_expand(data, &token->value[i+1]);
		//printf("key  : %s\n", key);

		if (ft_env_key_is_present(data, key))
		{
			//printf("key found\n");
			ft_rm_from_str(data, &(token->value), strlen(key)+ 1, i);
			ft_add_to_str(data, &(token->value), ft_env_get_value(data, key), i);
		}
		else
		{
			//printf("key not found\n");
			ft_rm_from_str(data, &(token->value), strlen(key)+ 1, i);
			//ft_rm_from_str(data, &str, strlen(key + 1), i);
		}
		}

		i++;

	}
	//ft_free(data, token->value);
	//token->value = str;
			printf("key 3\n");

}

// fct non testee
static int ft_is_next_word_to_expand(t_token *token)
{
	if (token->type == T_PIPE ||
		token->type == T_REDIRECT_IN ||
		token->type == T_REDIRECT_OUT ||
		token->type == D_REDIRECT_OUT ||
		token->type == D_QUOTE ||
		token->type == T_WORD)
	{
		return (1);
	}
	else if (token->type == T_HEREDOC ||
		token->type == S_QUOTE)
	{
		return (0);
	}
	else
	{
		ft_printf("erreur dans l'expand, le type du token est invalide\n");
		return (0);
	}
}

// fct non testee / a corriger en prenant que les mots qui ne suivent pas un heredoc (meme si on s'en fou au final
// car les heredoc seront deja faits)
void	ft_expand(t_data *data)
{
	t_token	*token;
	int		next_word_to_expand;

	token = data->tokens_list;
	next_word_to_expand = 1;
	while(token)
	{
		if (next_word_to_expand && token->type == T_WORD)
			ft_expand_token(data, token);
		if (token->type != T_SPACE)
			next_word_to_expand = ft_is_next_word_to_expand(token);
		token = token->next;
	}
}
