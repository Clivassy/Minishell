/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_garbage_collector.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:13:01 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:13:04 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_split_garbage_collector(t_data *data, char const *s, char c)
{
	char	**new_str;
	int		i;

	new_str = ft_split(s, c);
	if (!new_str)
		ft_exit(data);
	ft_add_to_garbage_collector(data, new_str);
	i = 0;
	while (new_str[i])
	{
		ft_add_to_garbage_collector(data, new_str[i]);
		i++;
	}
	return (new_str);
}

void	ft_free_split_garbage_collector(t_data *data, char **split_str)
{
	int		i;

	if (!split_str)
		return ;
	i = 0;
	while (split_str[i])
	{
		ft_free(data, split_str[i]);
		i++;
	}
	ft_free(data, split_str);
}
