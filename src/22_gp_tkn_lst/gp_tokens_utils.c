#include "minishell.h"

void    ft_fill_new_token_2(char *content, t_data *data, int type)
{
    t_token *new_token;

    new_token = ft_new_token(data, content, type);
    ft_lstadd_back_token(&data->gp_tokens_list, new_token);
}

int   ft_get_redir_tkn(t_data *data, char *content, int type)
{
    t_token *new_list;

    if (!content || !data)
        return(ERROR);
    if (type == T_REDIRECT_OUT)
        ft_fill_new_token_2(content, data, T_REDIRECT_OUT);
    if (type == T_REDIRECT_IN)
        ft_fill_new_token_2(content, data, T_REDIRECT_IN);
    if (type == T_HEREDOC)
        ft_fill_new_token_2(content, data, T_HEREDOC);
    if (type == D_REDIRECT_OUT)
        ft_fill_new_token_2(content, data, D_REDIRECT_OUT);
    return (0);
}

t_token *ft_fill_redir_tkn(t_data *data, t_token *list)
{
    if (list->next->type != T_SPACE)
    {
        ft_get_redir_tkn(data, list->next->value, list->type);
        list = list->next;
    }
    else if (list->next->type == T_SPACE)
    {
        ft_get_redir_tkn(data, list->next->next->value, list->type);
        list = list->next->next;
    }
    return (list);
}
