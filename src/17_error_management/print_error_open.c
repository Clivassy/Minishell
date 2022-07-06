#include "minishell.h"

void	ft_print_open_error(t_data *data, char *file_name)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(file_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(NULL);
}
