#include "minishell.h"

// close all the fd in exec_list exept those at the current_index
// if current_index < 0 all the fd will be close
void	ft_close_fd_exept_current(t_data *data, int current_index)
{
	t_exec_elm *exec_elm;

	exec_elm = data->exec_list;
	while(exec_elm)
	{
		//ft_printf("index:%d, close fdout: %d\n", current_index, exec_elm->fd_out);

		if (exec_elm->index != current_index)
			{
				//ft_print_fd_status("status avant close");

				if (exec_elm->fd_in != STDIN_FILENO && exec_elm->fd_in >= 0)
				{
					//ft_printf("index:%d, close fdin: %d\n", current_index, exec_elm->fd_in);
					if(close(exec_elm->fd_in) == -1)
						ft_exit_close_error(data);
					exec_elm->fd_in = -1;
				}
				if (exec_elm->fd_out != STDOUT_FILENO && exec_elm->fd_out >= 0)
				{
					//ft_printf("index:%d, close fdout: %d\n", current_index, exec_elm->fd_out);
					if(close(exec_elm->fd_out) == -1)
						ft_exit_close_error(data);
					exec_elm->fd_out = -1;
				}
			}
		exec_elm = exec_elm->next;
	}
}
		//ft_print_fd_status("status avant dup2");
