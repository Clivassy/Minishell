#include "minishell.h"

/* To put into header */
/*
typedef struct data_copy
{
	int		exit_asked;
    char	*read_line;
    char	**env;
	int		last_pipeline_exit_status;
	int		nb_of_process;
   // char **command_list;
    t_token	*tokens_list;
    t_token *gp_tokens_list;
    t_exec_elm	*exec_list;
    t_fd_heredoc  *fd_lst;
	int	fd_save_stdout;
	int	fd_save_stdin;
	t_list	*garbage_collector;
} data_copy;
*/


void	ft_sigint_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		exit(130);
	}
}

void	ft_handle_heredoc_signal(void)
{
	signal(SIGINT, &ft_sigint_heredoc);
}

void	ft_handle_ctrld_heredoc(t_data *data, char *end)
{
	ft_printf("minishell: warning : here-document");
	ft_printf("delimited by end_of_file (wanted `%s')\n", end);
	ft_exit(data);
}
