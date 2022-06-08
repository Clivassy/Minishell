#include "minishell.h"

void	ft_test_env(t_data *data)
{
	print_env(data->env);
	ft_printf("nombre de ligne env : %d\n", ft_env_nb_of_lines(data->env));

	ft_printf("value associe a la cle PWD: %s\n", ft_env_get_value(data, "PWD"));
	ft_printf("value associe a la cle XMODIFIERS: %s\n", ft_env_get_value(data, "XMODIFIERS"));


}

