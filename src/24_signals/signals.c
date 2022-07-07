#include "minishell.h"

void ft_handle_sigquit(int signal)
{
    if (signal == SIGKILL)
        exit(0);
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
        close(STDIN_FILENO);
        write(STDERR_FILENO, "\n", 1);
    }
}

/* handle ctrl -c*/
void ft_handle_sigint(int signal)
{
    ft_printf("\n");
    if (signal == SIGINT)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
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