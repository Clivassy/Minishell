/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:19:32 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/20 16:45:26 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitlen(char **split)
{
	size_t	size;

	if (!split)
		return (0);
	size = 0;
	while (*split != 0)
	{
		size++;
		split++;
	}
	return (size);
}
