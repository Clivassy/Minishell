#include "minishell.h"

//void	ft_set_exec_with_t_heredoc(t_data *data, t_token *token, int process)
//{
//	// a faire : check fct avec partie excec fonctionnelle
//	int	return_heredoc;
//	int	fd_infile;

//	//return_heredoc = fct_here_doc_julia(data, token, &fd_infile)
//	if (return_heredoc < 0)
//		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell
//	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
//		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
//	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_infile;
//}

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

void	ft_set_exec_with_t_heredoc(t_data *data, t_token *token, int process)
{
	// a faire : check fct avec partie excec fonctionnelle
	t_fd_heredoc	*fd_heredoc;

	fd_heredoc = ft_pop_first_fd_lst(data);
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_heredoc->fd;
	ft_free(data, fd_heredoc);
}


