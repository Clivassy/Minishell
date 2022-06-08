#include "minishell.h"

void	ft_data_initialisation(t_data *data)
{
	data->exit_asked = 0;
    data->env = NULL;
    data->tokens_list = NULL;
    data->exec_list = NULL;
	data->garbage_collector = NULL;
}
