/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:40 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:04:38 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strchr(const char *string, int searchedchar)
{
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)string;
	while (*str)
	{
		if ((char)searchedchar == *str)
			return ((char *)str);
		str++;
	}
	if (searchedchar == 0)
		return (str);
	return (NULL);
}
