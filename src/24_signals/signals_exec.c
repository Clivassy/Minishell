#include "minishell.h"

void ft_handle_exec_sigint(int signal)
{
    if (signal == SIGINT)
    {
        ft_printf("\n");
		exit(130);
    }
}

void    ft_handle_exec_signal(void)
{
    signal(SIGINT, &ft_handle_exec_sigint);
}