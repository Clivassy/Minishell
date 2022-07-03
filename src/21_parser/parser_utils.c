#include "minishell.h"

void ft_is_empty_list(t_token *list)
{
    while (list)
    {
        if (list->type != T_SPACE)
            return;
        list = list->next;
    }
    ft_lexer_error("Error: only space, tab or newlines");
}

int ft_is_redirect_err(t_token *token)
{
    if (token->type == T_REDIRECT_IN || token->type == T_REDIRECT_OUT
        || token->type == D_REDIRECT_OUT)
        return (1);
    return(0);
}

void ft_is_empty_pipe(t_token *token)
{
    t_token *tmp;

    int statut = 0;
    tmp = token;
    if (!tmp->next && tmp->type != T_WORD)
        ft_lexer_error("Error 5 : no word after last pipe");
    while (tmp)
    {
        if (tmp->type == T_WORD)
            statut = 1;
        if (tmp->type == T_PIPE && statut < 1)
            ft_lexer_error("error; no word between pipe");
        tmp = tmp->next;
    }
}