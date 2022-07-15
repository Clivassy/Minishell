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

static int	ft_is_in_garbage_collector(t_data *data, void *address)
{
	t_list	*elm;

	if (!address)
		return (0);
	elm = data->garbage_collector;
	while (elm)
	{
		if (elm->content == address)
		{
			return (1);
		}
		elm = elm->next;
	}
	return (0);
}

// cree un maillon a la fin du garbage_collector et definie le
// *content avec l'argument envoye
void	ft_add_to_garbage_collector(t_data *data, void *content)
{
	t_list	*new_elem;

	if (ft_is_in_garbage_collector(data, content))
	{
		ft_print_color(COLOR_RED);
		ft_printf("#############################################\n");
		ft_printf("###     attempt to add an elm already     ###\n");
		ft_printf("###       in the garbage collector        ###\n");
		ft_printf("###         -> element not added          ###\n");
		ft_printf("### adress doublon: ->%p<-\n", content);
		ft_printf("### doublon: ->%s<-\n", (char *)content);
		ft_printf("#############################################\n");
		ft_print_color(COLOR_NORMAL);
		return ;
	}
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
