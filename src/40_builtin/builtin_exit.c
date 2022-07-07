#include "minishell.h"

void	ft_builtin_exit(t_data *data)
{
	if (data->nb_of_process == 1)
		write(2, "exit\n", 5);
	ft_free_garbage_collector(data);
    exit(0);
}
