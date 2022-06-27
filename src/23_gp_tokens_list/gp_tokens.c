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

static void    ft_fill_new_token_2(char *content, t_data *data, int type)
{
    t_token *new_token;

    new_token = ft_new_token(content, type);
    ft_lstadd_back_token(&data->gp_tokens_list, new_token);
}

static int ft_is_redirect(t_token *curr)
{
    if (curr->type == T_REDIRECT_OUT || curr->type == T_REDIRECT_IN
        ||curr->type == T_HEREDOC || curr->type == D_REDIRECT_OUT)
        return(1);
    return(0);
}

int   ft_get_redirect_token(t_data *data, char *content, int type)
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

int ft_group_tokens(t_data *data)
{
    t_token *new_list;
    t_token *last_list;

    last_list = data->tokens_list;
    while (last_list)
    {
        if (!last_list->next)
           return(0);
        if (last_list->type == T_SPACE)
            last_list = last_list->next;
        if (ft_is_redirect(last_list))
        {
            if (last_list->next->type != T_SPACE)
            {
                ft_get_redirect_token(data, last_list->next->value, last_list->type);
                last_list = last_list->next;
            }
            else if (last_list->next->type == T_SPACE)
            {
                ft_get_redirect_token(data, last_list->next->next->value, last_list->type);
                last_list = last_list->next->next;
            }
        }
        else if (last_list->type == T_WORD)
            ft_fill_new_token_2(last_list->value, data, T_CMD);
        else if (last_list->type == T_PIPE)
            ft_fill_new_token_2(last_list->value, data, T_PIPE);
        last_list = last_list->next;
    }
    return (0);
}

//cat | lol | << file1>>file3