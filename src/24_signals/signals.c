#include "minishell.h"

void ft_handle_sigquit(int signal)
{
    if (signal == SIGQUIT)
    {
       ft_putstr_fd("\b\b  \b\b", 1);
    }
}

/* handle ctrl -c in heredoc */
/*void    ft_handle_heredoc_signal(t_data *data, int signal)
{

}*/
// bien faire la distinction ente si on est dans le process 
//child ou le parent process.

void    ft_handle_heredoc_signal(int signal)
{
    if(signal == SIGINT)
    {
       ft_putstr_fd("\b\b  \b\b", 1);
    }
}

/* handle ctrl -c*/
void ft_handle_sigint(int signal)
{
    if (signal == SIGINT)
    {
        ft_printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void    ft_handle_signals(void)
{
    if (signal(SIGINT, &sigaddset) == SIG_ERR)
        printf("error\n");
    signal(SIGINT, &ft_handle_sigint);
    signal(SIGQUIT, &ft_handle_sigquit);
}