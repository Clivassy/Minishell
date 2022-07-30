/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:52:09 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 08:52:50 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_unsigned_int(unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	size_t	str_size;
	char	*str;
	int		i;

	str_size = ft_size_unsigned_int(n);
	str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	str[str_size] = 0;
	if (n == 0)
		str[0] = '0';
	i = str_size - 1;
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

static size_t	ft_size_unsigned_int(unsigned int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
