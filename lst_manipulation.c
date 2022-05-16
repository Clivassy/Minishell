#include "minishell.h"

void    ft_lst_print(t_elm *elm)
{
	int i;
	int	j;

	if (!elm)
	{
		ft_printf("liste vide\n");
		return;
	}
	i= 0;
	while (elm)
	{
		ft_printf("----------------------------\n");
		ft_printf("| element %d : %p\n", i, elm);
		ft_printf("| cmd =");
		j = 0;
		while ((elm->cmd)[j])
		{
			ft_printf(" %s", elm->cmd[j]);
			j++;
		}
		ft_printf("\n| file_in = %d\n", elm->file_in);
		ft_printf("| file_out = %d\n", elm->file_out);
		ft_printf("| next element = %p\n", elm->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		elm = elm->next;
		i++;
	}
}   

void    ft_lst_add(t_elm **elm_list, t_elm *new_elm)
{
	t_elm	*last;

	if (*elm_list == NULL)
	{
		*elm_list = new_elm;
		return ;
	}
	if (new_elm != 0)
	{
		last = ft_lst_get_last_elm(*elm_list);
		last->next = new_elm;
	}
}

t_elm	*ft_lst_get_last_elm(t_elm *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
