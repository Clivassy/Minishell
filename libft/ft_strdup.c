/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:43 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:02:39 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	size;
	char	*pt;
	size_t	i;

	size = ft_strlen((char *)source);
	pt = (char *)malloc(sizeof(char) * (size + 1));
	if (!pt)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pt[i] = ((char *)source)[i];
		i++;
	}
	pt[i] = 0;
	return (pt);
}
