/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:45:03 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/14 18:55:26 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_is_hexa(unsigned int nb, const char c, int *count)
{
	char	base[16];

	if (c == 'x')
		ft_strncpy(base, "0123456789abcdef", sizeof(base));
	if (c == 'X')
		ft_strncpy(base, "0123456789ABCDEF", sizeof(base));
	if (nb > 15)
		ft_is_hexa(nb / 16, c, count);
	ft_putchar(base[nb % 16], count);
}
