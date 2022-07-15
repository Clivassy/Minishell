#include "minishell.h"

/* -----------------------------------------------------------
Descriptif : Set one variable and its value to env
Input format : export [variable]=[value]
If input format != [variable]=[value]
then : print error : minishell: unset: ': not a valid identifier.
(exit code == 1)
else
Proceed export
-----------------------------------------------------------------*/
void	ft_add_var_to_env(t_data *data, char **new_env, char *var, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		new_env[j] = ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[j]);
		i++;
		j++;
	}
	new_env[j] = ft_strdup(var);
	ft_add_to_garbage_collector(data, new_env[j]);
	data->env = new_env;
}

int	ft_is_arg_ok(t_data *data, char *cmd)
{
	int		i;
	char	*new_var;

	if (!ft_strchr(cmd, '='))
		return (0);
	i = 0;
	new_var = ft_env_get_key_on_line(data, &cmd[i]);
	if (ft_is_valid_identifier(new_var))
		return (1);
	return (0);
}

void	ft_create_new_env(t_data *data, char *value)
{
	char	**new_env;
	char	*var;
	int		len;

	len = ft_env_nb_of_lines(data->env) + 2;
	var = ft_env_get_key_on_line(data, value);
	new_env = ft_calloc(len, sizeof(char *));
	ft_add_to_garbage_collector(data, new_env);
	if (ft_env_key_is_present(data, var))
	{
		ft_rm_str_from_env(data, new_env, var, ft_env_nb_of_lines(data->env));
		len--;
	}
	ft_add_var_to_env(data, new_env, value, len - 2);
}

int	ft_builtin_export(t_data *data, char **cmd)
{
	int	i;
	int	exit_code;

	exit_code = 0;
	i = 1;
	if (!cmd[1])
		return (0);
	while (cmd[i])
	{
		if (ft_is_arg_ok(data, cmd[i]))
			ft_create_new_env(data, cmd[i]);
		else
		{
			ft_printf("minishel: unset: `%s':", cmd[i]);
			ft_printf(" not a valid identifier\n");
			exit_code = 1;
		}
		i++;
	}
	return (exit_code);
}
