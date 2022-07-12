#include "minishell.h"

void	ft_save_stdin_out(t_data *data)
{
	data->fd_save_stdin = dup(STDIN_FILENO);
	if (data->fd_save_stdin == -1)
		ft_exit_dup_error(data);

	data->fd_save_stdout = dup(STDOUT_FILENO);
	if (data->fd_save_stdout == -1)
		ft_exit_dup_error(data);
}

// restore stdin stdout and close the saves
void	ft_restore_stdin_out(t_data *data)
{
	if (dup2(STDIN_FILENO, data->fd_save_stdin) == -1)
		ft_exit_dup_error(data);
	if (dup2(STDOUT_FILENO, data->fd_save_stdout) == -1)
		ft_exit_dup_error(data);

	if(close(data->fd_save_stdin) == -1)
		ft_exit_close_error(data);
	data->fd_save_stdin = -1;
	if(close(data->fd_save_stdout) == -1)
		ft_exit_close_error(data);
	data->fd_save_stdout = -1;
}

void    ft_make_fd_redirection(t_data *data, t_exec_elm *exec_elm)
{
	//ft_printf("lancement processus, index: %d, pid %d\n", exec_elm->index, exec_elm->pid);
	//ft_printf("fd_in: %d, fd_out: %d\n", exec_elm->fd_in, exec_elm->fd_out);

	if (exec_elm->fd_in != STDIN_FILENO)
	{
		if (dup2(exec_elm->fd_in, STDIN_FILENO) == -1)
			ft_exit_dup_error(data);
	}
	if (exec_elm->fd_out != STDOUT_FILENO)
	{
		if (dup2(exec_elm->fd_out, STDOUT_FILENO) == -1)
			ft_exit_dup_error(data);
	}
}