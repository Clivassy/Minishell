/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:41:52 by jbatoro           #+#    #+#             */
/*   Updated: 2022/01/09 13:25:37 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_is_pointer(unsigned long long ptr, int *count)
{
	char	base[16];

	ft_strncpy(base, "0123456789abcdef", sizeof(base));
	if (ptr > 15)
		ft_is_pointer(ptr / 16, count);
	ft_putchar(base[ptr % 16], count);
}
