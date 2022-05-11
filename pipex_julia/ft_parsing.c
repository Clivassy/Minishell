/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:44:54 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/29 16:47:00 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/* Get PATHS of the ENV*/
void	ft_get_paths(t_pipex *input)
{
	int	i;

	i = 0;
	if (!input->env[0])
	{
		input->env[0] = PATH;
		input->env[1] = NULL;
	}
	else
	{
		while (!ft_strnstr(input->env[i], "PATH", 4))
		i++;
	}
	input->paths = ft_split(input->env[i] + 5, ':');
}

/* Init the cmd given the input */
void	ft_check_cmd(t_pipex *input, int index)
{
	if (index == 1)
		input->cmd = input->cmd1_arg[0];
	if (index == 2)
		input->cmd = input->cmd2_arg[0];
}

/* Check if cmd is a path */
int	ft_is_cmd_path(t_pipex *input)
{
	if (ft_strnstr(input->cmd, "/", ft_strlen(input->cmd)))
	{
		if (access(input->cmd, F_OK) == 0)
			return (1);
		else
			ft_cmd_error(&input->cmd, input);
	}
	return (0);
}

/* Check all paths*/
char	*ft_check_one_path(t_pipex *input, int index)
{
	char	*path;
	char	*end_slash_path;
	int		i;

	ft_check_cmd(input, index);
	if (ft_is_cmd_path(input))
		return (input->cmd);
	ft_get_paths(input);
	i = -1;
	while (input->paths[++i])
	{
		end_slash_path = ft_strjoin(input->paths[i], "/");
		path = ft_strjoin(end_slash_path, input->cmd);
		free(end_slash_path);
		if (access(path, F_OK) == 0)
		{
			ft_free(input->paths);
			return (path);
		}
		free(path);
	}
	ft_free(input->paths);
	return (0);
}
