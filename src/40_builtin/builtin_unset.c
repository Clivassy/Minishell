#include "minishell.h"

/*---------------------------------- DEBEUG ---------------------------------

  void    ft_debeug(t_data *data, char *msg, char **env, char *color)
  {
  ft_print_color(color);
  printf("--------------%s-----------\n", msg);
  ft_print_env(env);
  ft_print_color(COLOR_MAGENTA);
  printf("NUMBER = %d\n",ft_env_nb_of_lines(data->env));
  }
  -------------------------------------------------------------------------*/

/* -----------------------------------------------------------
Descriptif : remove variable from the env
-----------------------------------------------------------*/
/*
void	ft_rm_str_from_env(t_data *data, char **new_env, char *var, int len)
{
	int	i;
	int	j;
	int	status;

	status = 1;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strcmp(var, ft_env_get_key_on_line(data, data->env[i])) == 0
			&& status > 0)
		{
			if (i == len -1)
			{
				new_env[j] = NULL;
				data->env = new_env;
				return ;
			}
			new_env[j] = ft_is_last_line(data, i, len, j, new_env);
			status = -1;
			i++;
		}
		new_env[j] = ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[j]);
		i++;
		j++;
	}
	new_env[j] = NULL;
	data->env = new_env;
}*/




char	**ft_is_last_line(t_data *data, char **new_env, int i, int len)
{
	int j;

	j = i; 
	if (i == len -1)
	{
		new_env[j] = NULL;
		data->env = new_env;
		return (new_env);
	}
	return(NULL);
}

void	ft_rm_str_from_env(t_data *data, char **new_env, char *var, int len)
{
	int	i;
	int	j;
	int	status;

	status = 1;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strcmp(var, ft_env_get_key_on_line(data, data->env[i])) == 0
			&& status > 0)
		{
			if (ft_is_last_line(data, new_env, i, len))
				return;
			status = -1;
			i++;
		}
		new_env[j] = ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[j]);
		i++;
		j++;
	}
	new_env[j] = NULL;
	data->env = new_env;
}

void	ft_unset_variable(t_data *data, char *var)
{
	char	**new_env;
	int		i;

	new_env = ft_malloc(data,
			sizeof(char *) * (ft_env_nb_of_lines(data->env)));
	if (!new_env)
		ft_exit(data);
	i = 0;
	while (i < ft_env_nb_of_lines(data->env))
	{
		new_env[i] = NULL;
		i++;
	}
	ft_rm_str_from_env(data, new_env, var, ft_env_nb_of_lines(data->env));
}

/* return (1) if char is a valid identifier
   return(0) if char isn't a valid char */
int	ft_is_valid_identifier(char *cmd)
{
	int	i;

	i = 0;
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (0);
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_builtin_unset(t_data *data, char **cmd)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!cmd[1])
		return (0);
	while (cmd[i])
	{
		if (ft_is_valid_identifier(cmd[i]))
		{
			if (ft_env_key_is_present(data, cmd[i]) == 1)
				ft_unset_variable(data, cmd[i]);
		}
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
