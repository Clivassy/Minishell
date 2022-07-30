/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:36:53 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 08:58:23 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	total_size;

	total_size = count * size;
	pt = malloc(total_size);
	if (!pt)
	{
		return (NULL);
	}
	ft_bzero(pt, total_size);
	return (pt);
}
