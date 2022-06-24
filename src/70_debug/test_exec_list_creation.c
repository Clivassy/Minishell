#include "minishell.h"

void	ft_test_exec_list_creation(t_data *data)
{
	create_token_list_3(data);

	int	nb_of_pipe;
	nb_of_pipe = ft_count_pipe(data, data->tokens_list);
	ft_printf("nb of pipe: %d", nb_of_pipe);



}
