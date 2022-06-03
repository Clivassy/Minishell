/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:18:17 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/03 14:53:42 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free un element du garbage collector
void	ft_free(t_data *data, void *address)
{
	t_list	*previous;
	t_list	*next;
	t_list	*elm;

	if (!address)
		return ;
	elm = data->garbage_collector;
	previous = NULL;
	while (elm)
	{
		next = elm->next;
		if (elm->content == address)
		{
			free(elm->content);
			if (previous == NULL)
				data->garbage_collector = next;
			else
				previous->next = elm->next;
			free(elm);
		}
		previous = elm;
		elm = next;
	}
}
