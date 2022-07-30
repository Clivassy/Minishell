/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:00:50 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:00:55 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_initialisation(t_data *data, char **envp)
{
	data->exit_asked = 0;
	data->read_line = NULL;
	data->env = NULL;
	data->last_pipeline_exit_status = 0;
	data->nb_of_process = 0;
	data->tokens_list = NULL;
	data->gp_tokens_list = NULL;
	data->exec_list = NULL;
	data->fd_lst = NULL;
	data->fd_save_stdout = -1;
	data->fd_save_stdin = -1;
	data->garbage_collector = NULL;
	ft_init_ptr(data);
	ft_dup_env(data, envp);
}

void	ft_reinitialisation_read_data(t_data *data)
{
	data->read_line = NULL;
	data->nb_of_process = 0;
	data->tokens_list = NULL;
	data->gp_tokens_list = NULL;
	data->exec_list = NULL;
}
