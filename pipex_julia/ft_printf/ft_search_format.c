/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspdiuxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:33:04 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/09 13:26:53 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_search_format(va_list args, int *count, const char s)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), count);
	if (s == 's')
		ft_print_str(va_arg(args, char *), count);
	if (s == 'p')
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		ft_is_pointer(va_arg(args, unsigned long long), count);
	}
	if (s == 'd' || s == 'i')
		ft_is_i_or_d(va_arg(args, int), count);
	if (s == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), count);
	if (s == 'x' || s == 'X')
		ft_is_hexa(va_arg(args, unsigned int), s, count);
	if (s == '%')
		ft_putchar('%', count);
}
