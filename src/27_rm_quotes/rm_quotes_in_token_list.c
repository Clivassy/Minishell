#include "minishell.h"

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
