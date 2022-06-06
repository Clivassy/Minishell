/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:46:50 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/06 22:59:13 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_data_initialisation(t_data *data)
{
	data->exit_asked = 0;
    data->env = NULL;
    data->tokens_list = NULL;
    data->exec_list = NULL;
	data->garbage_collector = NULL;
}
