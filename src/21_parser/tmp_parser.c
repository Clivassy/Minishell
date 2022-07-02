#include "minishell.h"

int ft_is_redirect_err(t_token *token)
{
    if (token->type == T_REDIRECT_IN || token->type == T_REDIRECT_OUT
        || token->type == D_REDIRECT_OUT)
        return (1);
    return(0);
}

void ft_is_empy_pipe(t_token *token)
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
            ft_lexer_error("error pipe 6");
        tmp = tmp->next;
    }
}

int ft_pipe_errors(t_token *token)
{
    //printf("first token is : %d\n", token->type);
    if (!token->next)
        ft_lexer_error("Error 2 : pipe at the end");
    if (token->next->type == T_PIPE)
        ft_lexer_error("Error 3 : multiple pipes ");
    //token = token->next;
    ft_is_empy_pipe(token->next);
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
                ft_lexer_error("ERROR REDIECT 1");
            if (token->next->next->type != T_WORD)
                ft_lexer_error("ERROR REDIRECT 2");            
        }
        if (token->next->type != T_SPACE)
        {
            if(token->next->type != T_WORD)
                ft_lexer_error("ERROR REDIRECT 3");
        }
    }
   // printf("NO REDIRECT ERRORS\n");*/
    return (0);
}

int ft_parser(t_data *data)
{
    t_token *list;

    list = data->tokens_list;
    //check first token == pipe ou first token == space + | 
    if (list->type == T_PIPE)
        ft_lexer_error("Error 1 : pipe at the begining");
    while (list)
    {
        if (list->type == T_HEREDOC)
            printf("heredoc\n");
        if (list->type == T_PIPE)
            ft_pipe_errors(list);
        if (ft_is_redirect_err(list))
            ft_redirect_errors(list);
        list = list->next;
    }
    return (0);
}    