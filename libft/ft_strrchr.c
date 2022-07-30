/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:14 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/07 10:23:06 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strrchr(const char *string, int searchedchar)
{
	char	*last_found;

	if (!string)
		return (NULL);
	last_found = NULL;
	while (*string)
	{
		if (*string == (char)searchedchar)
			last_found = (char *)string;
		string++;
	}
	if (searchedchar == 0)
		last_found = (char *)string;
	return (last_found);
}
