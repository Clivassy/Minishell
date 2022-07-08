#include "minishell.h"

void    ft_handle_ctrld(t_data *data)
{
    write(1, "exit\n", 6);
    ft_exit(data);
}

void ft_handle_sigquit(int signal)
{
    if (signal == SIGQUIT)
        ft_putstr_fd("\b\b  \b\b", 1);
}

void    ft_handle_ctrld_heredoc(t_data *data)
{
    ft_putstr_fd("\b\b  \b\b", 1);
    ft_exit(data);
}

void ft_heredoc_sigint(int signal)
{
    if (signal == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
        rl_on_new_line();
		rl_redisplay();
	}
    /*if (signal == SIGINT)
    {
       exit(1);
    }*/
}

void   ft_handle_heredoc_signal(void)
{
    signal(SIGINT, &ft_heredoc_sigint);
}

/* handle ctrl -c*/
void ft_handle_sigint(int signal)
{
    if (signal == SIGINT)
    {
        ft_printf("\n");
        rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
    }
}

void    ft_handle_signals(void)
{
    if (signal(SIGINT, &ft_handle_sigint) == SIG_ERR)
        printf("error 1\n");
    if (signal(SIGQUIT, &ft_handle_sigquit) == SIG_ERR)
        printf("error 2\n");
}