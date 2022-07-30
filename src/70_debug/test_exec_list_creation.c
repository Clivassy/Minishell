#include "minishell.h"

void	ft_test_exec_list_creation(t_data *data)
{
	ft_exec_elm_lst_print(data->exec_list);
	create_token_list_3(data);
	//create_token_list_empty(data);
	//create_token_list_1_elm(data);
	//create_token_list_3elm_avec_pipe(data);


	int	nb_of_pipe;
	nb_of_pipe = ft_count_pipe(data, data->tokens_list);
	ft_printf("nb of pipe: %d\n", nb_of_pipe);

	ft_create_exec_elm_list(data);

	ft_exec_elm_lst_print(data->exec_list);


}
