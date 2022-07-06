#include "minishell.h"

t_exec_elm	*ft_create_new_exec_elm(t_data *data)
{
    t_exec_elm  *new_elm;

    new_elm = ft_malloc(data, sizeof(t_exec_elm));
	if (!new_elm)
		ft_exit(data);
    new_elm->cmd = ft_malloc(data, sizeof(char*) * 1);
	if (!new_elm->cmd)
		ft_exit(data);
	(new_elm->cmd)[0] = NULL;
    new_elm->fd_in = -1;
    new_elm->fd_out = -1;
    new_elm->index = -1;
	new_elm->has_redirect_pb = 0;
    new_elm->pid = -1;
    new_elm->next = NULL;
    return (new_elm);
}

void    ft_add_exec_elm(t_exec_elm **elm_list, t_exec_elm *new_elm)
{
	t_exec_elm	*last;

	if (*elm_list == NULL)
	{
		*elm_list = new_elm;
		return ;
	}
	if (new_elm != 0)
	{
		last = ft_get_last_exec_elm(*elm_list);
		last->next = new_elm;
	}
}

t_exec_elm	*ft_create_empty_exec_elm_list(t_data *data, int nb_elm)
{
	int	i;
	t_exec_elm	*list;
	t_exec_elm	*new_exec_elm;

	i = 0;
	list = NULL;
	while (i < nb_elm)
	{
		new_exec_elm = ft_create_new_exec_elm(data);
		new_exec_elm->index = i;
		ft_add_exec_elm(&list, new_exec_elm);
		i++;
	}
	return (list);
}

t_exec_elm	*ft_get_last_exec_elm(t_exec_elm *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_exec_elm	*ft_get_exec_elm(t_exec_elm *lst, int index)
{
	int	i;

	if (!lst)
		return (NULL);
	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (NULL);
}
