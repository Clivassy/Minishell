/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:55:24 by jbatoro           #+#    #+#             */
/*   Updated: 2022/04/09 18:55:52 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *s, ...);
void		ft_putchar(int c, int *count);
void		ft_search_format(va_list args, int *count, const char s);
void		ft_is_hexa(unsigned int nb, const char c, int *count);
void		ft_is_i_or_d(int nb, int *count);
void		ft_is_pointer(unsigned long long ptr, int *count);
void		ft_print_str(char *str, int *count);
void		ft_print_unsigned(unsigned int n, int *count);
char		*ft_utoa(unsigned int nb);
char		*ft_strncpy(char *dest, char *src, int n);

#endif
