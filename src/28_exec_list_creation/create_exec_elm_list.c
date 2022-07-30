/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_exec_elm_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:30 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:08:32 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	*ft_create_pipe(t_data *data)
{
	int	*fd_pipe;

	fd_pipe = ft_malloc(data, sizeof(int) * 2);
	if (!fd_pipe)
		ft_exit(data);
	if (pipe(fd_pipe) == -1)
		ft_exit_pipe_error(data);
	return (fd_pipe);
}

static void	ft_create_pipe_between_process(t_data *data)
{
	int	i;
	int	*fd_pipe;

	i = 0;
	ft_get_exec_elm(data->exec_list, 0)->fd_in = 0;
	ft_get_exec_elm(data->exec_list, data->nb_of_process - 1)->fd_out = 1;
	while (i < data->nb_of_process - 1)
	{
		fd_pipe = ft_create_pipe(data);
		ft_get_exec_elm(data->exec_list, i)->fd_out = fd_pipe[1];
		ft_get_exec_elm(data->exec_list, i + 1)->fd_in = fd_pipe[0];
		i++;
	}
}

void	ft_create_exec_elm_list(t_data *data)
{
	data->nb_of_process = ft_count_pipe(data, data->gp_tokens_list) + 1;
	data->exec_list = ft_create_empty_exec_elm_list(data, data->nb_of_process);
	ft_create_pipe_between_process(data);
}
