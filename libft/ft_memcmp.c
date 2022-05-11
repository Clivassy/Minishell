/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:02 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 11:06:15 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	if (size == 0)
		return (0);
	if (!pointer1 && !pointer2)
		return (0);
	if (!pointer1)
		return (-*((unsigned char *)pointer2));
	if (!pointer2)
		return (*((unsigned char *)pointer1));
	pt1 = (unsigned char *)pointer1;
	pt2 = (unsigned char *)pointer2;
	i = 0;
	while (i < size - 1 && (*(pt1 + i) == *(pt2 + i)))
	{
		i++;
	}
	return (*(pt1 + i) - *(pt2 + i));
}
