#include "minishell.h"

int	ft_exit_error_too_many_arg(t_data *data)
{
	write(STDERR_FILENO, "bash: exit: too many arguments\n", 31);
	return (1);
}

int	ft_exit_error_not_numeric_arg(t_data *data, char *arg)
{
	write(STDERR_FILENO, "bash: exit: ", ft_strlen("bash: exit: "));
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, ": numeric argument required\n", ft_strlen(": numeric argument required\n"));

	return (2);
}