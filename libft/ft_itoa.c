/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:37:13 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 08:59:06 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_int(long n);

char	*ft_itoa(int n)
{
	long	nb;
	size_t	str_size;
	char	*str;
	int		i;

	nb = (long)n;
	str_size = ft_size_int(nb);
	str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	str[str_size] = 0;
	str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		nb = -nb;
	i = str_size - 1;
	while (nb != 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

static size_t	ft_size_int(long n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
