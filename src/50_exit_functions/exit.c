#include "minishell.h"

void	ft_exit(t_data *data)
{
	ft_free_garbage_collector(data);
	exit(0);
}

// renomer ft_exit et changer partout
void	ft_exit2(t_data *data, int error_status)
{
	ft_free_garbage_collector(data);
	exit(error_status);
}
