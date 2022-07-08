#include "minishell.h"
static void	ft_wait_pid(t_data *data)
{
	t_exec_elm *exec_elm;
	int	return_status;

	return_status = -1;
	exec_elm = data->exec_list;
	while(exec_elm)
	{
		//ft_printf("attente fin processus: %d\n", exec_elm->index);
		//waitpid(exec_elm->pid, &(data->last_pipeline_exit_status), 0); // remplacer NULL pour avoir l'id status
		waitpid(exec_elm->pid, &return_status, 0); // remplacer NULL pour avoir l'id status
		//printf("pid: %d, return status: %d\n", exec_elm->pid, return_status);
		//printf("pid: %d, conv status: %d\n", exec_elm->pid, WEXITSTATUS(return_status));
		// partie a verifier
		if(WIFEXITED(return_status))
		{
			data->last_pipeline_exit_status = WEXITSTATUS(return_status);
		}
		else
			data->last_pipeline_exit_status = return_status;
		exec_elm = exec_elm->next;
	}
}

void	ft_exec_cmd_with_many_processus(t_data *data)
{
	int curent_index;
	t_exec_elm *exec_elm;
	pid_t id;

	curent_index = 0;
	exec_elm = data->exec_list;
	while(exec_elm)
	{
	printf("test\n");

		id = fork();
		if (id < 0)
			ft_exit_fork_error(data);
		else if (id == 0)
		{
			if (exec_elm->has_redirect_pb == 1)
			{
				ft_close_fd_exept_current(data, -1);
				ft_exit2(data, 1);
			}
			ft_close_fd_exept_current(data, curent_index);
			ft_exec_one_command(data, exec_elm);
		}
		else
			exec_elm->pid = id;
		//sleep(1);
		curent_index++;
		exec_elm = exec_elm->next;
	}
	ft_close_fd_exept_current(data, -1);
	ft_wait_pid(data);


}

void	ft_exec_cmd_with_one_processus(t_data *data)
{
	t_exec_elm *exec_elm;

	exec_elm = data->exec_list;
	if (exec_elm->has_redirect_pb == 1)
	{
		data->last_pipeline_exit_status = 1;
		return ;
	}
	if (!exec_elm->cmd || !(exec_elm->cmd)[0] )
		return ;
	if (ft_strcmp((exec_elm->cmd)[0], "exit") == 0)
	{
		ft_close_fd_exept_current(data, -1);
		ft_builtin_exit(data);
	}
	else
		ft_exec_cmd_with_many_processus(data);


}

void    ft_exec_all_cmds(t_data *data)
{
	if(data->nb_of_process == 1)
	{
		ft_exec_cmd_with_one_processus(data);
	}
	else
	{
		ft_exec_cmd_with_many_processus(data);
	}
}


