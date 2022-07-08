#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs
// realine pour recuperer tout ce qui vient jusqu'au EOF
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ??
----------------------------------------------------------------------*/
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
            ft_handle_ctrld_heredoc(data);
        if (ft_strcmp(str, heretag) == 0)
            break;
        if (exp > 0 && ft_is_expand_required(str))
            ft_expand_str(data, &str);
        tmp = ft_strjoin(tmp, str);
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

void ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    char *str;
    char *here_tag;
    int file[2];
    t_fd_heredoc *fd_list;
    
    fd_list = NULL;
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    str = ft_read_heredoc(data, here_tag);
    if (!str)
        ft_exit(data);
    write(file[1], str, ft_strlen(str)+ 1);
    /*///// TMP ///////
    ft_test(file);
    ////// TMP /////*/
    fd_list = ft_new_fd(data, file[0]);
    ft_lstadd_back_fd(&data->fd_lst, fd_list);
	if( close(file[1]) == -1)
		ft_exit_close_error(data);
}
