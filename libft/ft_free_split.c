/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:49:59 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/20 16:42:07 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **split_result)
{
	int	i;

	if (split_result)
	{
		i = 0;
		while (split_result[i])
		{
			free(split_result[i]);
			split_result[i] = NULL;
			i++;
		}
		free(split_result);
		split_result = NULL;
	}
}
