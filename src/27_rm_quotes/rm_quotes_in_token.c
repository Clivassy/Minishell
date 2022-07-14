#include "minishell.h"

// rm quotes dans la value d'un token
void	ft_rm_quotes_in_token(t_data *data, t_token *token)
{
	int		double_quote_open;
	int		simple_quote_open;
	int		i;

	double_quote_open = 0;
	simple_quote_open = 0;
	i = 0;
	while (token->value[i])
	{
		if (double_quote_open)
			double_quote_open = manage_open_d_quote(data, &token->value, &i);
		else if (simple_quote_open)
			simple_quote_open = manage_open_s_quote(data, &token->value, &i);
		else
		{
			if (token->value[i] == '"')
				double_quote_open = manage_close_d_quote(data, &token->value,
						&i);
			else if (token->value[i] == '\'')
				simple_quote_open = manage_close_s_quote(data, &token->value,
						&i);
		}
		i++;
	}
}

// rm quotes dans str
void	ft_rm_quotes_in_str(t_data *data, char **str)
{
	int		double_quote_open;
	int		simple_quote_open;
	int		i;

	double_quote_open = 0;
	simple_quote_open = 0;
	i = 0;
	while ((*str)[i])
	{
		if (double_quote_open)
			double_quote_open = manage_open_d_quote(data, str, &i);
		else if (simple_quote_open)
			simple_quote_open = manage_open_s_quote(data, str, &i);
		else
		{
			if ((*str)[i] == '"')
				double_quote_open = manage_close_d_quote(data, str, &i);
			else if ((*str)[i] == '\'')
				simple_quote_open = manage_close_s_quote(data, str, &i);
		}
		i++;
	}
}
