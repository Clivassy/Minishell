#include "minishell.h"

/*----------------------------- GROUP _TOKENS LIST  ------------------------------


-----------------------------------------------------------------------*/

int ft_gp_tokens(t_data *data)
{
    t_token *new_list;
    t_token *last_list;

    new_list = new_list;
    last_list = data->tokens_list;
    data->gp_tokens_list = NULL;
    //ft_print_token_list(data->tokens_list);
    while (last_list)
    {
        if (last_list->type == T_HEREDOC)
        {
            new_list = ft_new_token(last_list->next->value, T_HEREDOC);
            ft_lstadd_back_token(&data->gp_tokens_list, new_list);   
        }
        last_list = last_list->next;
    }
    ft_print_token_list(data->gp_tokens_list);
    return (0);
}