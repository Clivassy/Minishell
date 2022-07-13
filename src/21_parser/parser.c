#include "minishell.h"

int ft_pipe_errors(t_token *token)
{
    //printf("first token is : %d\n", token->type);
    if (!token->next)
        return(SYNTAX_ERR_PIPE);
    if (token->next->type == T_PIPE)
        return(SYNTAX_ERR_PIPE);
    if (ft_is_empty_pipe(token->next) == SYNTAX_ERR_PIPE)
        return(SYNTAX_ERR_PIPE);
    return(0);
}

int ft_redirect_errors(t_token *token)
{
    if (ft_is_redirect_err(token))
    {
        //printf("token type is : %s\n", token->value);
        if (!token->next)
            return(SYNTAX_ERR_NEWLINE);
        if (token->next->type == T_SPACE)
        {
            if (!token->next->next)
                return(SYNTAX_ERR_NEWLINE);
            if (ft_is_next_tkn_ok(token->next->next->type)
                != 0)
                return(ft_is_next_tkn_ok(token->next->next->type));
        }
        if (token->next->type != T_SPACE)
        {
            if (ft_is_next_tkn_ok(token->next->type)
                != 0)
                return(ft_is_next_tkn_ok(token->next->type));
        }
    }
    return (0);
}

int ft_is_heredoc(t_data *data, t_token *list)
{
    if (list->next->type == T_SPACE)
    {
        if (!list->next->next)
            return(SYNTAX_ERR_NEWLINE);
        if (list->next->next->type == T_HEREDOC)
            return(SYNTAX_ERR_HEREDOC);
        if (list->next->next->type == T_PIPE)
            return(SYNTAX_ERR_PIPE);
        ft_heredoc(data, list->next->next);
    }
    else
    {
        if(list->next->type != T_WORD)
            return(SYNTAX_ERR_HEREDOC);
        ft_heredoc(data, list->next);
    }
    return (0);
}

int ft_parser(t_data *data)
{
    t_token *list;
    int error_status;

    list = data->tokens_list;
    error_status = ft_pre_parser(data, list);
    if (error_status > 0)
        return(error_status);
    while (list)
    {
        if (list->type == T_HEREDOC)
        {
            if (!list->next)
                return(SYNTAX_ERR_NEWLINE);
            error_status = ft_is_heredoc(data, list);
        }
        if (list->type == T_PIPE)
            error_status = ft_pipe_errors(list);
        if (ft_is_redirect_err(list))
            error_status = ft_redirect_errors(list);
        if (error_status > 0)
            return(error_status);
        list = list->next;
    }
    return (0);
}    