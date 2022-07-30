/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:12:10 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:12:13 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_exit(t_data *data)
{
	int	i;

	ft_free_garbage_collector(data);
	i = 0;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

// renomer ft_exit et changer partout
void	ft_exit2(t_data *data, int error_status)
{
	int	i;

	ft_free_garbage_collector(data);
	i = 0;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(error_status);
}
