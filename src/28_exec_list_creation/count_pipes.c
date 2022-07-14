#include "minishell.h"

int	ft_count_pipe(t_data *data, t_token *token_list)
{
	int	nb_of_pipe;

	nb_of_pipe = 0;
	while (token_list)
	{
		if (token_list->type == T_PIPE)
			nb_of_pipe += 1;
		token_list = token_list->next;
	}
	return (nb_of_pipe);
}
