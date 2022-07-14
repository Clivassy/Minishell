#include "minishell.h"

void	ft_handle_ctrld(t_data *data)
{
	write(1, "exit\n", 6);
	ft_exit(data);
}

void	ft_handle_sigquit(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_handle_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_handle_signals(void)
{
	signal(SIGINT, &ft_handle_sigint);
	signal(SIGQUIT, &ft_handle_sigquit);
}
