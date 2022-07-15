#include "minishell.h"

void	ft_set_exec_with_t_heredoc(t_data *data, t_token *token, int process)
{
	(void)token;
	t_fd_heredoc	*fd_heredoc;

	fd_heredoc = ft_pop_first_fd_lst(data);
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_heredoc->fd;
	ft_free(data, fd_heredoc);
}
