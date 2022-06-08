#include "minishell.h"

int ft_env_nb_of_lines(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    return (i);
}

// return char* between 0 and the first '='
// return NULL if not valid (empty line, no '=' or empty string before '=')
char *ft_env_get_key_on_line(t_data *data, char *line)
{
	//char *key;
	//char *previous_key;
	//size_t	key_size;
	//int	i;

	//if (!line)
	//	return (NULL);
	//key = NULL;
	//key_size = 0;
	//i = 0;
	//while (line[i] && line[i] != '=')
	//{
	//	key_size++;
	//	previous_key = key;
	//	key = ft_malloc(data, sizeof(char) * key_size);
	//	if (!key)
	//		ft_exit(data);
	//	ft_strlcpy(key, previous_key, key_size - 1);
	//	key[key_size]
	//	ft_free(data, previous_key);
	//	i++;
	//}
	char	*copy_line;
	int		i;

	copy_line = ft_strdup((const char *)line);
	if (!copy_line)
		ft_exit(data);
	ft_add_to_garbage_collector(data, copy_line);
	i = 0;
	while (copy_line[i] && copy_line[i] != '=')
	{
		i++;
	}
	if (copy_line[i] == '=')
	{
		copy_line[i] = '\0';
		return(copy_line);
	}
	else
		return (NULL);
}

char *ft_env_get_value_on_line(t_data *data, char *line)
{
	char	*copy_line;
	int		i;

	i = 0;
	while (line[i] != '=')
	{
		i++;
	}
	i++;
	copy_line = ft_strdup(&line[i]);
	if (!copy_line)
		ft_exit(data);
	ft_add_to_garbage_collector(data, copy_line);
	return (copy_line);
}

// fonction pour le moment non utilisee
int	ft_env_key_is_present(t_data *data, char *key_searched)
{
	int		i;
	char	*key;

	i = 0;
	while (data->env[i])
	{
		key = ft_env_get_key_on_line(data, data->env[i]);
		if (ft_strncmp(key, key_searched, strlen(key_searched)) == 0)
		{
			return (1);
		}
		ft_free(data, key);
		i++;
	}
	return (0);
}

char *ft_env_get_value(t_data *data, char *key_searched)
{
	int		i;
	char	*key;

	i = 0;

	while (data->env[i])
	{
		key = ft_env_get_key_on_line(data, data->env[i]);
		if (ft_strncmp(key, key_searched, strlen(key_searched)) == 0)
			return (ft_env_get_value_on_line(data, data->env[i]));
		i++;
	}
	return (NULL);
}

