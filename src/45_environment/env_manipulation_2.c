#include "minishell.h"

char	*ft_env_get_value(t_data *data, char *key_searched)
{
	int		i;
	char	*key;

	i = 0;
	while (data->env[i])
	{
		key = ft_env_get_key_on_line(data, data->env[i]);
		if (ft_strncmp(key, key_searched, ft_strlen(key_searched)) == 0)
			return (ft_env_get_value_on_line(data, data->env[i]));
		i++;
	}
	return (NULL);
}
