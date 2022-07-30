/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:37:58 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:42:36 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memchr(const void *memoryblock, int searchedchar, size_t size)
{
	unsigned char	*pt;

	if (!memoryblock)
		return (NULL);
	pt = (unsigned char *)memoryblock;
	while (size)
	{
		if (*pt == (unsigned char)searchedchar)
			return ((void *)pt);
		size--;
		pt++;
	}
	return (NULL);
}
