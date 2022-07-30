/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:21 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:04:35 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_size;
	size_t	return_size;
	char	*pt;
	size_t	i;

	if (s == 0)
		return (NULL);
	s_size = ft_strlen((char *)s);
	return_size = s_size - start;
	if (start >= s_size)
		return_size = 0;
	if (return_size > len)
		return_size = len;
	pt = (char *)malloc(sizeof(char) * (return_size + 1));
	if (!pt)
		return (NULL);
	i = 0;
	while (i < return_size)
	{
		pt[i] = ((char *)s)[start + i];
		i++;
	}
	pt[i] = 0;
	return (pt);
}
