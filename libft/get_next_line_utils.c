/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:29:07 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/15 21:21:16 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (*str != 0)
	{
		size++;
		str++;
	}
	return (size);
}

char	*ft_initbuffer(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}

int	ft_has_eol(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_buflen(char *str)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (i < BUFFER_SIZE && str[i] != 0 && str[i] != '\n')
	{
		size++;
		str++;
		i++;
	}
	if (str[i] == '\n')
		size++;
	return (size);
}
