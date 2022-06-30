#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/

char *ft_stock_here_doc(t_data *data, char *str, char *temp, char *heretag)
{
    while (1)
    {
        str = readline("> ");
        if (!str)
            ft_exit(data);
        if (ft_strcmp(str, heretag) != 0)
            temp = ft_strjoin(temp, "\n");
        if (ft_strcmp(str, heretag) == 0)
            break;
        else
            temp = ft_strjoin(temp, str);
    }
    return(temp);
}

char *ft_read_heredoc(t_data *data, char *str, char *heretag)
{
    char *temp;

    // je l'add pas au garbage car je vais la libérer directement ds ma fct.
    temp = ft_strdup("");
    // expand 
    temp = ft_stock_here_doc(data, str, temp, heretag);
    return (temp);
}

int ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    char *str;
    char *here_tag;
    int len;
    int file[2];

    len = ft_strlen(heredoc_tkn->value);
    // voir avec yann pr ft_malloc OU malloc
    here_tag = malloc(sizeof(char*) * len + 1);
    if (!here_tag)
        ft_exit(data);
    here_tag = heredoc_tkn->value;
    pipe(file);
    str = ft_read_heredoc(data, str, here_tag);
    write(file[1], str, ft_strlen(str)+ 1);
    ft_test(file);
    free(str);
    free(here_tag);
    return (file[0]);
}