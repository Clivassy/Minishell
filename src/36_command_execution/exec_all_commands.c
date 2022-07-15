#include "minishell.h"

static void	ft_wait_pid(t_data *data)
{
	t_exec_elm	*exec_elm;
	int			return_status;

	return_status = 1;
	exec_elm = data->exec_list;
	while (exec_elm)
	{
		// TBD ajouter macro pour capter signal stop (voir man waitpid)
		waitpid(exec_elm->pid, &return_status, 0);
		if (WIFSIGNALED(return_status))
		{
			if (WIFSIGNALED(return_status) == 1)
				data->last_pipeline_exit_status = 130;
		}
		else if (WIFEXITED(return_status))
		{
			data->last_pipeline_exit_status = WEXITSTATUS(return_status);
		}
		else
			data->last_pipeline_exit_status = return_status;
		exec_elm = exec_elm->next;
	}
}

void	ft_exec_cmd_list_with_fork(t_data *data)
{
	int			curent_index;
	t_exec_elm	*exec_elm;
	pid_t		id;

	curent_index = 0;
	exec_elm = data->exec_list;
	while (exec_elm)
	{
		id = fork();
		if (id < 0)
			ft_exit_fork_error(data);
		else if (id == 0)
		{
			signal(SIGINT, SIG_DFL);
			//signal(SIGQUIT, SIG_DFL);
			ft_handle_exec_signal();
			ft_close_fd_exept_current(data, curent_index);
			ft_exec_one_command(data, exec_elm);
		}
		else
			exec_elm->pid = id;
		curent_index++;
		exec_elm = exec_elm->next;
	}
	ft_close_fd_exept_current(data, -1);
	ft_wait_pid(data);
}

void	ft_exec_cmd_with_one_processus(t_data *data)
{
	t_exec_elm	*exec_elm;

	exec_elm = data->exec_list;
	if (exec_elm->has_redirect_pb == 1)
	{
		ft_close_fd_exept_current(data, -1);
		data->last_pipeline_exit_status = 1;
		return ;
	}
	if (!exec_elm->cmd || !(exec_elm->cmd)[0])
		return ;
	if (ft_is_builtin(data, exec_elm->cmd))
	{
		ft_save_stdin_out(data);
		ft_make_fd_redirection(data, exec_elm);
		ft_exec_builtin(data, exec_elm->cmd);
		ft_close_fd_exept_current(data, -1);
		ft_restore_stdin_out(data);
	}
	else
		ft_exec_cmd_list_with_fork(data);
}

void	ft_exec_all_cmds(t_data *data)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (data->nb_of_process == 1)
	{
		ft_exec_cmd_with_one_processus(data);
	}
	else
	{
		ft_exec_cmd_list_with_fork(data);
	}
}
