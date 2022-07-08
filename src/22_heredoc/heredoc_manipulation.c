#include "minishell.h"

t_fd_heredoc	*ft_new_fd(t_data *data, int fd)
{
	t_fd_heredoc	*new;

	new = (t_fd_heredoc*)ft_malloc(data, sizeof(t_fd_heredoc));
	if (!new)
		ft_exit(data);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_fd_heredoc	*ft_lstlast_fd(t_fd_heredoc*lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_fd(t_fd_heredoc **alst, t_fd_heredoc *new)
{
	t_fd_heredoc	*last;

	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	if (new != 0)
	{
		last = ft_lstlast_fd(*alst);
		last->next = new;
	}
}

void    ft_print_fds_list(t_fd_heredoc *fd_list)
{
	if (!fd_list)
	{
		ft_printf("liste vide\n");
		exit(EXIT_FAILURE);
	}
	while (fd_list != NULL)
	{
		ft_printf("----------------------------\n");
		ft_printf("\n| type = %d\n", fd_list->fd);
		ft_printf("| next element = %p\n", fd_list->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		fd_list = fd_list->next;
	}
}

// return le 1er element de la fd_lst et le retire de la liste
// /!\ l'element n'est pas free, il faudra le free dans la fonction qui le recupere
t_fd_heredoc *ft_pop_first_fd_lst(t_data *data)
{
	t_fd_heredoc	*first_fd;

	if (!data->fd_lst)
		return (NULL);
	first_fd = data->fd_lst;
	data->fd_lst = data->fd_lst->next;
	return (first_fd);
}
