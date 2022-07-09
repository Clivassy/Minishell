#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs
// realine pour recuperer tout ce qui vient jusqu'au EOF
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ??
----------------------------------------------------------------------*/
/*void    ft_stock_heredoc(int fd[2], int exp, t_data *data, char *heretag)
{
    char *str;

    t_fd_heredoc *fd_list;
    char *tmp;
    tmp = ft_strdup("");
    fd_list = NULL;
    ft_add_to_garbage_collector(data, tmp);
    str = NULL;
    while (1)
    {
        ft_handle_heredoc_signal();
        str = readline("> ");
        ft_add_to_garbage_collector(data, str);
        // printf("STRING 1= %s\n", tmp);
        if (str == NULL)
            ft_handle_ctrld_heredoc(data, heretag);
        if (ft_strcmp(str, heretag) == 0)
            break;
        if (exp > 0 && ft_is_expand_required(str))
            ft_expand_str(data, &str);
        tmp = ft_strjoin(tmp, str);
        ft_add_to_garbage_collector(data, tmp);
        tmp = ft_strjoin(tmp, "\n");
        ft_add_to_garbage_collector(data, tmp);
        write(fd[1], tmp,ft_strlen(tmp) + 1);
    }
    fd_list = ft_new_fd(data, fd[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);
//    ft_test(fd);
}

void    ft_read_heredoc(int fd[2], t_data *data, char *heretag)
{
    printf("LOL\n");
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

    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    id = fork();
    if (id == 0)
    {
        close(file[0]);
        signal(SIGINT, SIG_DFL);
        ft_read_heredoc(file, data, here_tag);
    }
	if( close(file[1]) == -1)
		ft_exit_close_error(data);
   if (waitpid(id, &(data->last_pipeline_exit_status), 0) < 0)
        ft_exit(data);
   //ft_test(file);
    return(0);
}*/


/*/////////////// VERSION FONCTONNELLE ///////////////////////////*/
char *ft_stock_heredoc(int exp, t_data *data, char *tmp, char *heretag)
{
    char *str;

    str = NULL;
    while (1)
    {   
        ft_handle_heredoc_signal();
        str = readline("> ");
        ft_add_to_garbage_collector(data, str);
        if (str == NULL)
        {
            
            ft_handle_ctrld_heredoc(data, heretag);
        }
        if (ft_strcmp(str, heretag) == 0)
            break;
        if (exp > 0 && ft_is_expand_required(str))
            ft_expand_str(data, &str);
        tmp = ft_strjoin(tmp, str);
        ft_add_to_garbage_collector(data, tmp);
        tmp = ft_strjoin(tmp, "\n");
        ft_add_to_garbage_collector(data, tmp);
    }
    return(tmp);
}

char *ft_read_heredoc(t_data *data, char *heretag)
{
    char *tmp;
    int expand;

    expand = 0;
    tmp = ft_strdup("");
    ft_add_to_garbage_collector(data, tmp);
    if (ft_is_quoted(heretag))
        expand = 1;
    tmp = ft_stock_heredoc(expand, data, tmp, heretag);
    return (tmp);
}

int ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    pid_t id; 
    char *str;
    char *here_tag;
    int file[2];
    t_fd_heredoc *fd_list;
    
    fd_list = NULL;
    id = 0;
    
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    id = fork();
    //proteger
    if (id == 0)
    {   
        signal(SIGINT, SIG_DFL);
        //securiser le close
        close(file[0]);
        str = ft_read_heredoc(data, here_tag);
        write(file[1], str, ft_strlen(str)+ 1);
        close(file[1]);
        ft_exit(data);
    }
    if (!str)
        ft_exit(data);
    waitpid(id, &(data->last_pipeline_exit_status), 0);
   // ft_test(file);
    fd_list = ft_new_fd(data, file[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);
	if( close(file[1]) == -1)
		ft_exit_close_error(data);
    return (0);
}

/*
void    ft_stock_heredoc(int file[2], int exp, t_data *data, char *heretag)
{
    char *str;
    char *tmp;
    t_fd_heredoc *fd_list;

    str = NULL;
    fd_list = NULL;
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
        tmp = ft_strjoin(tmp, str);
        ft_add_to_garbage_collector(data, tmp);
        tmp = ft_strjoin(tmp, "\n");
        ft_add_to_garbage_collector(data, tmp);
        write(file[1], str, ft_strlen(str)+ 1);
    }
    fd_list = ft_new_fd(data, file[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);
}

void    ft_read_heredoc(int file[2], t_data *data, char *heretag)
{
    char *tmp;
    int expand;

    expand = 0;
    if (ft_is_quoted(heretag))
        expand = 1;
    ft_stock_heredoc(file, expand, data, heretag);
}

int ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    pid_t id; 
    char *here_tag;
    int file[2];
    
    id = 0;
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    id = fork();
    if (id == 0)
    {   
        signal(SIGINT, SIG_DFL);
        close(file[0]);
        ft_read_heredoc(file, data, here_tag);
        //write(file[1], str, ft_strlen(str)+ 1);
    }
    waitpid(id, &(data->last_pipeline_exit_status), 0);
   // ft_test(file);

	if( close(file[1]) == -1)
		ft_exit_close_error(data);
    return (0);
}*/