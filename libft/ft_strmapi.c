/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:03 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:03:44 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			str_len;
	char			*pt;
	unsigned int	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen((char *)s);
	pt = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!pt)
		return (NULL);
	i = 0;
	while (s[i])
	{
		pt[i] = (*f)(i, s[i]);
		i++;
	}
	pt[i] = 0;
	return (pt);
}
