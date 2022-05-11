/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:44:11 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/09 13:25:23 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_nb_is_neg(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		ft_putchar('-', count);
		n = -n;
		ft_is_i_or_d(n, count);
	}
}

void	ft_is_i_or_d(int n, int *count)
{
	if (n >= 0 && n <= 9)
	{
		n = n + 48;
		ft_putchar(n, count);
	}
	else if (n < 0)
		ft_nb_is_neg(n, count);
	else
	{
		ft_is_i_or_d(n / 10, count);
		ft_is_i_or_d(n % 10, count);
	}
}
