/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_terminated_tab_len.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:12:46 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:12:50 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

// calcul la longueur d'un tableau tab termine par un NULL
// (sans compter le NULL a la fin)
// retourne 0 si tab = NULL
size_t	ft_null_terminated_tab_len(char **tab)
{
	size_t	size;

	if (!tab)
		return (0);
	size = 0;
	while (tab[size] != 0)
	{
		size++;
	}
	return (size);
}
