#include "minishell.h"

// check if str == "-n" || "-nn..n"
static int	ft_is_n_flag(char *str)
{
	int	i;
	int	flag_n_found;

	if (!str)
		return (0);
	i = 0;
	flag_n_found = 0;
	if (str[0] == '-')
	{
		i = 1;
		while (str[i] == 'n')
		{
			flag_n_found = 1;
			i++;
		}
		if (str[i] == '\0' && flag_n_found)
			return (1);
	}
	return (0);
}

static void	ft_print_argument_list(char **argument_list)
{
	int	i;
	int	first_arg;

	i = 0;
	first_arg = 1;
	while (argument_list[i])
	{
		if (first_arg)
			first_arg = 0;
		else
			ft_printf(" ");
		ft_printf("%s", argument_list[i]);
		i++;
	}
}

int	ft_echo(char **cmd)
{
	int	n_flag_found;
	int	print_begin;

	if (!cmd || !cmd[0])
		return (0);
	if (cmd[1] == 0)
	{
		write(STDIN_FILENO, "\n", 2);
		return (0);
	}
	n_flag_found = 0;
	print_begin = 1;
	while (ft_is_n_flag(cmd[print_begin]))
	{
		n_flag_found = 1;
		print_begin += 1;
	}
	ft_print_argument_list(&(cmd[print_begin]));
	if (!n_flag_found)
		ft_printf("\n");
	return (0);
}
