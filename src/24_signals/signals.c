#include "minishell.h"

void ft_handle_sigquit(int signal)
{

}
/* handle ctrl -c in heredoc */
/*void    ft_handle_heredoc_signal(t_data *data, int signal)
{

}*/
// bien faire la distinction ente si on est dans le process 
//child ou le parent process.


/* handle ctrl -c*/
void ft_handle_sigint(int signal)
{
    ft_printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    return ;
}

void    ft_handle_signals(void)
{
    signal(SIGINT, &ft_handle_sigint);
    //signal(SIGQUIT, &ft_handle_sigquit)
}