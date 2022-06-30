#include "minishell.h"

void	create_exec_list_1(t_data *data)
{
	create_gp_token_list_1(data);

	ft_fill_exec_list(data);
}
