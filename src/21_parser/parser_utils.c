#include "minishell.h"

/* error: redirect followed by space and no word */
int	ft_is_next_tkn_ok(int type)
{
	if (type == T_PIPE)
		return (SYNTAX_ERR_PIPE);
	if (type == T_REDIRECT_IN)
		return (SYNTAX_ERR_REDIRECT_IN);
	if (type == T_REDIRECT_OUT)
		return (SYNTAX_ERR_REDIRECT_OUT);
	if (type == D_REDIRECT_OUT)
		return (SYNTAX_ERR_D_REDIRECT_OUT);
	if (type == T_HEREDOC)
		return (SYNTAX_ERR_HEREDOC);
	return (0);
}

int	ft_pre_parser(t_data *data, t_token *list)
{
	if (!ft_is_empty_list(list))
		return (TAB_OR_SPC_ERR);
	if (list->type == T_PIPE)
		return (SYNTAX_ERR_PIPE);
	if (list->type == T_SPACE)
	{
		if (list->next->type == T_PIPE)
			return (SYNTAX_ERR_PIPE);
	}
	return (0);
}

int	ft_is_empty_list(t_token *list)
{
	while (list)
	{
		if (list->type != T_SPACE)
			return (1);
		list = list->next;
	}
	return (0);
}

int	ft_is_redirect_err(t_token *token)
{
	if (token->type == T_REDIRECT_IN || token->type == T_REDIRECT_OUT
		|| token->type == D_REDIRECT_OUT)
		return (1);
	return (0);
}

int	ft_is_empty_pipe(t_token *token)
{
	t_token	*tmp;
	int		statut;

	status = 0;
	tmp = token;
	if (!tmp->next && tmp->type != T_WORD)
		return (SYNTAX_ERR_PIPE);
	while (tmp)
	{
		if (tmp->type == T_WORD)
			statut = 1;
		if (tmp->type == T_PIPE && statut < 1)
			return (SYNTAX_ERR_PIPE);
		tmp = tmp->next;
	}
	return (0);
}
