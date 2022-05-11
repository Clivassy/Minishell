/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:50 by ybellot           #+#    #+#             */
/*   Updated: 2022/03/18 20:40:10 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*pt;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	pt = malloc(sizeof(char) * total_size);
	if (!pt)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		pt[i + j] = s2[j];
		j++;
	}
	pt[i + j] = 0;
	return (pt);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*final_str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	final_str = ft_strjoin(tmp, s3);
	if (!final_str)
		return (NULL);
	return (final_str);
}
