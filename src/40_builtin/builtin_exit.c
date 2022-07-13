#include "minishell.h"

static	int	ft_is_number(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_builtin_exit(t_data *data, char **cmd)
{
	int return_statut;

	if (ft_null_terminated_tab_len(cmd) > 1)
	{
		if (!ft_is_number(cmd[1]))
			return (ft_exit_error_not_numeric_arg(data, cmd[1]));
		if (ft_null_terminated_tab_len(cmd) > 2)
			return (ft_exit_error_too_many_arg(data));
	}

	if (data->nb_of_process == 1)
		write(2, "exit\n", 5);

	if (ft_null_terminated_tab_len(cmd) == 1)
		return_statut = 0;
	else
		return_statut = ft_atoi(cmd[1]);
	ft_exit2(data, return_statut);
	return (return_statut);
	// verif free des fd dans ce cas particulier
}
