/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:18 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:04:19 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_count_first_trim(char const *s, char const *set);
static size_t	ft_count_last_trim(char const *s, char const *set);
static int		ft_is_in_set(char c, char const *set);
static char		*ft_create_empty_str(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*pt;
	size_t	i;

	if (s1 == 0 || set == 0)
		return (NULL);
	start = ft_count_first_trim(s1, set);
	end = ft_count_last_trim(s1, set);
	if (start == ft_strlen((char *)s1))
		return (ft_create_empty_str());
	pt = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				- start - end + 1));
	if (!pt)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1) - end - start)
	{
		pt[i] = s1[i + start];
		i++;
	}
	pt[i] = 0;
	return (pt);
}

static size_t	ft_count_first_trim(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_is_in_set(s[i], set))
	{
		i++;
	}
	return (i);
}

static size_t	ft_count_last_trim(char const *s, char const *set)
{
	size_t	nb;
	int		i;

	nb = 0;
	i = ft_strlen((char *)s) - 1;
	while (ft_is_in_set(s[i], set))
	{
		nb++;
		i--;
	}
	return (nb);
}

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_create_empty_str(void)
{
	char	*pt;

	pt = (char *)malloc(sizeof(char) * 1);
	if (!pt)
		return (NULL);
	pt[0] = 0;
	return (pt);
}
