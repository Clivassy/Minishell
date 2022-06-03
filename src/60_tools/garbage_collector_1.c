/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:18:17 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/03 14:53:51 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// initialise le pointeur du GC
void	ft_init_garbage_collector(t_data *data)
{
	data->garbage_collector = NULL;
}

// alloue memoire
// ajout element dans garbage collector
// return pointeur sur allocation ou NULL si erreur d'allocation
void	*ft_malloc(t_data *data, size_t size)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		return (NULL);
	ft_add_to_garbage_collector(data, allocated);
	return (allocated);
}

// cree un maillon a la fin du garbage_collector et definie le
// *content avec l'argument envoye
void	ft_add_to_garbage_collector(t_data *data, void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		ft_exit(data);
	new_elem->content = content;
	new_elem->next = NULL;
	ft_lstadd_back(&data->garbage_collector, new_elem);
}

// free tous les content du GC
// free les elements du GC
// reinitialise le GC
void	ft_free_garbage_collector(t_data *data)
{
	t_list	*next;
	t_list	*elm;

	elm = data->garbage_collector;
	while (elm)
	{
		next = elm->next;
		if (elm->content)
			free(elm->content);
		free(elm);
		elm = next;
	}
	ft_init_garbage_collector(data);
}

// affiche le contenu du garbage collector
void	ft_print_garbage_collector(t_data *data)
{
	int		i;
	t_list	*elm;

	ft_print_color(COLOR_CYAN);
	if (!data->garbage_collector)
	{
		ft_printf("garbage collector vide\n");
		ft_print_color(COLOR_NORMAL);
		return ;
	}
	i = 0;
	elm = data->garbage_collector;
	while (elm)
	{
		ft_printf("----------------------------\n");
		ft_printf("| element %d : %p\n", i, elm);
		ft_printf("| content adress = %p\n", elm->content);
		ft_printf("| next element = %p\n", elm->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		elm = elm->next;
		i++;
	}
	ft_print_color(COLOR_NORMAL);
}
