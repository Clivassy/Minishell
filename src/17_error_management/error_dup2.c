#include "minishell.h"

void	ft_exit_dup_error(t_data *data)
{
	perror(NULL);
	ft_exit2(data, 1);
}