#include "minishell.h"

void	ft_print_error(t_data *data, int error_status)
{
	if (error_status == SYNTAX_ERR_PIPE)
		ft_printf("bash: syntax error near unexpected token `|'\n");
	else
		ft_printf("error detected, unknown status\n");
}
