#include "minishell.h"

int	ft_builtin_env(t_data *data, char **cmd)
{
	(void)cmd;
	char	**env;

	env = data->env;
	if (!env)
		return (0);
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
	return (0);
}
