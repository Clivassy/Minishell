#include "minishell.h"

int ft_pipe_errors(t_token *token)
{
    //printf("first token is : %d\n", token->type);
    if (!token->next)
        ft_lexer_error("Error 2 : pipe at the end");
    if (token->next->type == T_PIPE)
        ft_lexer_error("Error 3 : multiple pipes ");
    //token = token->next;
    ft_is_empty_pipe(token->next);
   // printf("NO PIPE ERRORS\n");
    return(0);
}

int ft_redirect_errors(t_token *token)
{
    if (ft_is_redirect_err(token))
    {
        if (!token->next)
            ft_lexer_error("Error: nothing after redirect");
        if (token->next->type == T_SPACE)
        {
            if (!token->next->next)
                // bash: syntax error near unexpected token `newline'
                ft_lexer_error("error: redirect followed by space and nothing");
            if (token->next->next->type != T_WORD)
                ft_lexer_error("error: redirect followed by space and no word");            
        }
        if (token->next->type != T_SPACE)
        {
            if(token->next->type != T_WORD)
                ft_lexer_error("error: redirect is not followed by word");
        }
    }
   // printf("NO REDIRECT ERRORS\n");*/
    return (0);
}

int ft_is_heredoc(t_data *data, t_token *list)
{
   // printf("TOKEN = %s\n",list->next->value);
    if (list->next->type == T_SPACE)
    {
       // printf("TOKEN = %s\n",list->next->value);
        if (!list->next->next)
            ft_lexer_error("error: only space after last heredoc");
        if (list->next->next->type != T_WORD)
            ft_lexer_error("error 1: no heretag after heredoc");
        ft_heredoc(data, list->next->next);
    }
    else
    {
        if(list->next->type != T_WORD)
            ft_lexer_error("error 4: NO WORD after heredoc");
        ft_heredoc(data, list->next);
    }
    return (0);
}

/* check les listes avec seulement espaces ou tab 
+ pipe at the begining
+ space suivi d'un pipe at the beggining*/ 
int ft_pre_parser(t_data *data, t_token *list)
{
    ft_is_empty_list(list);
    if (list->type == T_PIPE)
        ft_lexer_error("Error 1 : pipe at the begining");
    if (list->type == T_SPACE)
    {
        if (list->next->type == T_PIPE)
            ft_lexer_error("Error 2 : space followed by pipe at the beggining");
    }
    return (0);
}

int ft_parser(t_data *data)
{
    t_token *list;

    list = data->tokens_list;
    ft_pre_parser(data, list);
    while (list)
    {
        if (list->type == T_HEREDOC)
        {
            if (!list->next)
                ft_lexer_error("Error 0: Nothing after heredoc");
            ft_is_heredoc(data, list);
        }
        if (list->type == T_PIPE)
            ft_pipe_errors(list);
        if (ft_is_redirect_err(list))
            ft_redirect_errors(list);
        list = list->next;
    }
    return (0);
}    