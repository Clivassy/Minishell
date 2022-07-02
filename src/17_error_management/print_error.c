#include "minishell.h"

void	ft_print_error(t_data *data, int error_status)
{
	// implementer les codes erreurs : utilisaion de constante dans un .h dedie
	ft_printf("error detected, status: %d\n", error_status);
}
