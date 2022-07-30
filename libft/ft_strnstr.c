/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:11 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 11:19:53 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	int		diff_found;

	if (!s1 || !s2)
		return (NULL);
	if (*s2 == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < len)
	{
		diff_found = 0;
		j = 0;
		while (s2[j] && !diff_found && (i + j) < len)
		{
			if (s1[i + j] != s2[j])
				diff_found = 1;
			j++;
		}
		if (!diff_found && s2[j] == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
