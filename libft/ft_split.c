/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:33 by ybellot           #+#    #+#             */
/*   Updated: 2021/12/13 09:02:19 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char separator);
static char	*ft_strcpy_until_c(char *str, char c);
static char	**ft_get_words(char **pt_return, char *s, int word_count, char c);
static void	ft_free(char **pt_return, int last_to_free);

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**pt_return;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	pt_return = (char **)malloc(sizeof(char **) * (word_count + 1));
	if (!pt_return)
		return (NULL);
	pt_return = ft_get_words(pt_return, (char *)s, word_count, c);
	return (pt_return);
}

static char	**ft_get_words(char **pt_return, char *s, int word_count, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			pt_return[j] = ft_strcpy_until_c(&s[i], c);
			if (!pt_return[j])
			{
				ft_free(pt_return, j);
				return (NULL);
			}
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	pt_return[j] = NULL;
	return (pt_return);
}

static void	ft_free(char **pt_return, int last_to_free)
{
	while (last_to_free >= 0)
	{
		free(pt_return[last_to_free]);
		last_to_free--;
	}
	free (pt_return);
}	

static int	ft_word_count(const char *s, char separator)
{
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	while (s[i])
	{	
		while (s[i] == separator && s[i])
			i++;
		if (s[i])
			word_count++;
		while (s[i] != separator && s[i])
			i++;
	}
	return (word_count);
}

static char	*ft_strcpy_until_c(char *s, char c)
{
	int		i;
	char	*cpy_str;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	cpy_str = malloc(sizeof(char) * (i + 1));
	if (!cpy_str)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		cpy_str[i] = s[i];
		i++;
	}
	cpy_str[i] = 0;
	return (cpy_str);
}
