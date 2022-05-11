/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:41:12 by ybellot           #+#    #+#             */
/*   Updated: 2022/03/18 23:48:58 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_launch_command(char *cmd, char **envp)
{
	char	**cmd_split;
	char	*command_with_path;

	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		ft_error("malloc error");
	command_with_path = ft_find_command(cmd_split[0], envp);
	if (execve(command_with_path, cmd_split, envp) == -1)
		ft_error("error in command execution");
	ft_error("error on function launch_command");
}

char	*ft_find_command(char *cmd, char **envp)
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
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				ft_error("error with ft_split");
			full_path = ft_check_path_command(paths, cmd);
			if (full_path)
			{
				ft_free_pointer_array(paths);
				return (full_path);
			}
		}
		i++;
	}
	ft_free_pointer_array(paths);
	return (NULL);
}

char	*ft_check_path_command(char **paths, char *cmd)
{
	int		j;
	char	*full_path;

	j = 0;
	while (paths[j])
	{
		full_path = ft_strjoin3(paths[j], "/", cmd);
		if (!full_path)
			ft_error("error with ft_join3");
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
			free(full_path);
		j++;
	}
	return (NULL);
}
