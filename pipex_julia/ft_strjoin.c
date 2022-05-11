/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:10:49 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/29 16:48:10 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*string;
	char	*string2;

	string = (char *)s1;
	string2 = (char *)s2;
	i = 0;
	while (string[i])
		i++;
	j = 0;
	while (string2[j])
	{
		string[i] = string2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str_join;
	unsigned int	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_join = (char *)malloc(sizeof(char) * len);
	if (!(str_join))
		return (NULL);
	str_join = ft_strcpy(str_join, s1);
	str_join = ft_strcat(str_join, s2);
	return (str_join);
}
