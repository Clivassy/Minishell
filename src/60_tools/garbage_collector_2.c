#include "minishell.h"

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

// free un element du garbage collector
void	ft_free(t_data *data, void *address)
{
	t_list	*previous;
	t_list	*next;
	t_list	*elm;

	if (!address)
		return ;
	elm = data->garbage_collector;
	previous = NULL;
	while (elm)
	{
		next = elm->next;
		if (elm->content == address)
		{
			free(elm->content);
			elm->content = NULL;
			if (previous == NULL)
				data->garbage_collector = next;
			else
				previous->next = elm->next;
			free(elm);
		}
		previous = elm;
		elm = next;
	}
}
