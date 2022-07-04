#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/

int ft_expand_heredoc(t_data *data, char **str)
{
    printf("---PROCEED EXPAND-----\n");
    //ft_expand_str(data, str);
    // call yann fct that will expand the char *
    return(0);
}

char *ft_stock_heredoc(int exp, t_data *data, char *tmp, char *heretag)
{
    char *str; 

    str = NULL;
    while (1)
    {
        str = readline("> ");
        if (!str)
            ft_exit(data);
        if (ft_strcmp(str, heretag) != 0)
            tmp = ft_strjoin(tmp, "\n");
        if (ft_strcmp(str, heretag) == 0)
            break;
        if (exp > 0 && ft_is_expand_required(str))
            ft_expand_heredoc(data, &str);
        tmp = ft_strjoin(tmp, str);
    }
    return(tmp);
}

char *ft_read_heredoc(t_data *data, char *heretag)
{
    char *tmp;
    int expand;

    expand = 0;
    // je l'add pas au garbage car je vais la libérer directement ds ma fct.
    tmp = ft_strdup("");
    if (ft_is_quoted(heretag))
        expand = 1;
    tmp = ft_stock_heredoc(expand, data, tmp, heretag);
    return (tmp);
}

void	ft_rm_quotes_in_str(t_data *data, char **str);
//int ft_heredoc(t_data *data, t_token *heredoc_tkn)
void ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    char *str;
    char *here_tag;
    int file[2];
    t_fd_heredoc *fd_list;

    fd_list = malloc(sizeof(t_fd_heredoc));
    here_tag = heredoc_tkn->value;
    ft_rm_quotes_in_str(data, &here_tag);
    if (pipe(file) == -1)
        ft_exit(data);
    str = ft_read_heredoc(data, here_tag);
    if (!str)
        ft_exit(data);
    write(file[1], str, ft_strlen(str)+ 1);
    free(str);
    ///// TMP ///////
    ft_test(file);
    ////// TMP /////
    fd_list->fd = file[0];
    //close(file[1]);
}