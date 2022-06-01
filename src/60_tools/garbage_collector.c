/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:18:17 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/02 00:22:15 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creer structure (list chainee) garbage collector dans t_data (.h)
// voir si on envoie aux fct data ou le pointeur du 1er element de garbage collector

void	ft_init_garbage_collector(t_data *data)
{
	// initialise le pointeur du GC
}

void	*ft_malloc(t_data *data, size_t size)
{
	// alloue memoire
	// ajout element dans garbage collector
	// return pointeur sur allocation ou -1 si erreur
}

void	ft_add_elm_garbage_collector(t_data *data, void *content)
{
	// creer un maillon et ajoute le pointeur content
}

void	ft_free_garbage_collector(t_data *data)
{
	// free tous les content du GC
	// free les elements du GC
	// reinitialise le GC
}

