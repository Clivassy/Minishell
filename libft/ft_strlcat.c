/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:54 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:38:52 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	return_size;

	if (!dst || !src)
		return (0);
	if (size == 0 || size < ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	return_size = ft_strlen((char *)dst) + ft_strlen((char *)src);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (i < size - 1 && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (return_size);
}
