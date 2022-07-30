/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:09:56 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:09:59 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	*ft_strjoin3(t_data *data, char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*final_str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		ft_exit(data);
	ft_add_to_garbage_collector(data, tmp);
	final_str = ft_strjoin(tmp, s3);
	if (!final_str)
		ft_exit(data);
	ft_add_to_garbage_collector(data, final_str);
	ft_free(data, tmp);
	return (final_str);
}

// check if 1 path is valid in the paths list and return the 1st valid
char	*ft_check_path_command(t_data *data, char **paths, char *cmd)
{
	int		j;
	char	*full_path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	j = 0;
	while (paths[j])
	{
		full_path = ft_strjoin3(data, paths[j], "/", cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
			ft_free(data, full_path);
		j++;
	}
	return (NULL);
}

char	*ft_find_command(t_data *data, char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			paths = ft_split_garbage_collector(data, envp[i] + 5, ':');
			full_path = ft_check_path_command(data, paths, cmd);
			ft_free_split_garbage_collector(data, paths);
			if (full_path)
			{
				return (full_path);
			}
			ft_free(data, full_path);
		}
		i++;
	}
	return (NULL);
}
