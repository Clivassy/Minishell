#include "minishell.h"

int	ft_is_space_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return(1);
	return(0);
}

void    ft_fill_new_token(char *content, t_data *data, int type)
{
    t_token *new_token;

    new_token = ft_new_token(content, type);
    ft_lstadd_back_token(&data->tokens_list, new_token);
}

/* Return 1 if readline token is a word (if no metachracters are found) */
int ft_is_word(char *line, int index)
{
    if (line[index] == '<' || line[index] == '>'
       || line[index] == ' ' || line[index] == '|')
            return(0);
    return (1);
}

int	ft_check_unclose_quote(char	*line)
{
	int		i;
    int quote;

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