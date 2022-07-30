/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:09 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:34:59 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdlib.h>
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	if (!destination || !source)
		return (NULL);
	if (source >= destination)
	{
		ft_memcpy(destination, source, size);
	}
	else
	{
		while (size)
		{
			((char *)destination)[size - 1] = ((char *)source)[size - 1];
			size--;
		}
	}
	return (destination);
}
