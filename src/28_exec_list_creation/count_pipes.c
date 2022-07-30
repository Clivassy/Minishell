/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:08:12 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:08:16 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_count_pipe(t_data *data, t_token *token_list)
{
	int	nb_of_pipe;

	(void)data;
	nb_of_pipe = 0;
	while (token_list)
	{
		if (token_list->type == T_PIPE)
			nb_of_pipe += 1;
		token_list = token_list->next;
	}
	return (nb_of_pipe);
}
