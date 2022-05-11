/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:47:24 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/29 16:47:42 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static char	**ft_split_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_malloc_word(const char *str, int start, int end)
{
	char	*malloc_w;
	int		i;
	int		len;

	i = 0;
	len = (end - start) + 1;
	malloc_w = (char *)malloc(sizeof(char) * len);
	if (!malloc_w)
		return (0);
	while (start < end)
	{
		malloc_w[i] = str[start];
		i++;
		start++;
	}
	malloc_w[i] = '\0';
	return (malloc_w);
}

static char	**ft_malloc_array(char const *s, char **array, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if ((s[i] != c) && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			array[j] = ft_malloc_word(s, index, i);
			if (!array[j])
				return (ft_split_free(array));
			index = -1;
			j++;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_malloc_array(s, array, c);
	return (array);
}
