#include "minishell.h"

//void	ft_rm_quotes_in_tokens_list(t_data *data)
//{
//	t_token	*token;


//	// boucle sur les token
//		// boucle sur la str
//		// SI double open
//		// SI simple open
//		// sinon
//	token = data->tokens_list;
//	while (token)
//		{
//			ft_rm_quotes_in_token(data, token->value);
//			token = token->next;
//		}
//}

static int	check_and_rm_d_quote(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '"')
	{
		ft_rm_from_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

static int	check_and_rm_s_quote(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '\'')
	{
		ft_rm_from_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

void	ft_rm_quotes_in_token(t_data *data, t_token *token)
{
	int		double_quote_open;
	int		simple_quote_open;
	int		i;

	double_quote_open = 0;
	simple_quote_open = 0;
	i = 0;
	while(token->value[i])
	{
		if (double_quote_open)
			double_quote_open = check_and_rm_d_quote(data, &token->value, &i);
		else if (simple_quote_open)
			simple_quote_open = check_and_rm_s_quote(data, &token->value, &i);
		else
		{
			if (token->value[i] == '"')
			{
				double_quote_open = 1;
				ft_rm_from_str(data, &token->value, 1, i);
				i--;
			}
			else if (token->value[i] == '\'')
			{
				simple_quote_open = 1;
				ft_rm_from_str(data, &token->value, 1, i);
				i--;
			}
		}
		i++;
	}
}
