/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:12 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:33:28 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*dest;

	if (!pointer)
		return (NULL);
	dest = (char *)pointer;
	i = 0;
	while (i < count)
	{
		*(dest + i) = (char)value;
		i++;
	}
	return (pointer);
}
