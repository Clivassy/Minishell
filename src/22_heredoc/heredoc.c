#include "minishell.h"

void    ft_stock_heredoc(int fd[2], int exp, t_data *data, char *heretag)
{
    char *str;
    char *tmp;
   // t_fd_heredoc *fd_list;

    //fd_list = NULL;
    str = NULL;
    tmp = ft_strdup("");
    ft_add_to_garbage_collector(data, tmp);

    while (1)
    {
        ft_handle_heredoc_signal();
        str = readline("> ");
        ft_add_to_garbage_collector(data, str);
        if (str == NULL)
            ft_handle_ctrld_heredoc(data, heretag);
        if (ft_strcmp(str, heretag) == 0)
            break;
        if (exp > 0 && ft_is_expand_required(str))
            ft_expand_str(data, &str);
       // tmp = ft_strjoin(tmp, str);
       // ft_add_to_garbage_collector(data, tmp);
      //  tmp = ft_strjoin(tmp, "\n");
      //  ft_add_to_garbage_collector(data, tmp);
        write(fd[1], str, ft_strlen(str) + 1);
        write(fd[1], "\n", 1);
       // ft_test(fd);
    }
    //printf("STRING = %s\n", tmp);
   /* fd_list = ft_new_fd(data, fd[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);*/
   // ft_print_fds_list(data->fd_lst);
}

void    ft_read_heredoc(int fd[2], t_data *data, char *heretag)
{
    int expand;

    expand = 0;
    if (ft_is_quoted(heretag))
        expand = 1;
    ft_stock_heredoc(fd, expand, data, heretag);
}

int ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    int id;
    char *here_tag;
    int file[2];
    t_fd_heredoc *fd_list;

    fd_list = NULL;
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    fd_list = ft_new_fd(data, file[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);
    // fct init list
    id = fork();
    if (id == -1)
        ft_exit(data);
    if (id == 0)
    {
        signal(SIGINT, SIG_DFL);
        ft_read_heredoc(file, data, here_tag);
    }
	if( close(file[1]) == -1)
		ft_exit_close_error(data);
    if (waitpid(id, &(data->last_pipeline_exit_status), 0) < 0)
        ft_exit(data);
    return(0);
}