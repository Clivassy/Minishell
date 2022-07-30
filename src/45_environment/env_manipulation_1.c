/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manipulation_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:11:41 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:11:44 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_env_nb_of_lines(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

// return char* between 0 and the first '='
// return NULL if not valid (empty line, no '=' or empty string before '=')
char	*ft_env_get_key_on_line(t_data *data, char *line)
{
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
		return (copy_line);
	}
	else
		return (NULL);
}

char	*ft_env_get_value_on_line(t_data *data, char *line)
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

int	ft_max_len(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

int	ft_env_key_is_present(t_data *data, char *key_searched)
{
	int		i;
	char	*key;

	if (!key_searched)
		return (0);
	i = 0;
	while (data->env[i])
	{
		key = ft_env_get_key_on_line(data, data->env[i]);
		if (ft_strncmp(key, key_searched, ft_max_len(key, key_searched)) == 0)
		{
			return (1);
		}
		ft_free(data, key);
		i++;
	}
	return (0);
}
