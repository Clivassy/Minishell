#include "minishell.h"

/* check les listes avec seulement espaces ou tab 
+ pipe at the begining
+ space suivi d'un pipe at the beggining*/ 
int ft_pre_parser(t_data *data, t_token *list)
{
    // a placer au tout debut
    if (!ft_is_empty_list(list))
        ft_lexer_error("error : only space and tab");
    if (list->type == T_PIPE)
        return(SYNTAX_ERR_PIPE);
        //ft_lexer_error("Error 1 : pipe at the begining");
    if (list->type == T_SPACE)
    {
        if (list->next->type == T_PIPE)
            return(SYNTAX_ERR_PIPE);
           // ft_lexer_error("Error 2 : space followed by pipe at the beggining");
    }
    return (0);
}

int ft_is_empty_list(t_token *list)
{
    while (list)
    {
        if (list->type != T_SPACE)
            return (1);
        list = list->next;
    }
    //ft_lexer_error("Error: only space, tab or newlines");
    return (0);
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