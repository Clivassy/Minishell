#include "minishell.h"

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
	printf("bash: warning : here-document");
	printf("delimited by end_of_file (wanted `%s')\n", end);
	ft_exit(data);
}
