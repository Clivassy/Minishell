#include "minishell.h"

static int ft_is_redirect(t_token *curr)
{
    if (curr->type == T_REDIRECT_OUT || curr->type == T_REDIRECT_IN
        ||curr->type == T_HEREDOC || curr->type == D_REDIRECT_OUT)
        return(1);
    return(0);
}

int ft_group_tokens(t_data *data)
{
	// possible de return un void
    t_token *new_list;
    t_token *list;

    list = data->tokens_list;
    while (list)
    {
        if (!list->next && list->type != T_WORD)
           return(0);
        if (list->type == T_SPACE)
            list = list->next;
        if (ft_is_redirect(list))
            list = ft_fill_redir_tkn(data, list);
        else if (list->type == T_WORD)
            ft_fill_new_token_2(list->value, data, T_CMD);
        else if (list->type == T_PIPE)
            ft_fill_new_token_2(list->value, data, T_PIPE);
        list = list->next;
    }
    return (0);
}
