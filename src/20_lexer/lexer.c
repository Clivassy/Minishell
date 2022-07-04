#include "minishell.h"

/*----------------------------- LEXER ------------------------------

1 ) Récupérer la string entrée en input avec readline = OK

2 ) Stocker dans une liste chaînée les différents tokens.
DOLLARS $
PIPE |
REDIRECT_IN <
REDIRECT_OUT >
HEREDOC <<
D_REDIRECT_OUT >>
S_QUOTE '
D_QUOTE "
SPACE ' '

Tout ce qui est situé entre ces métacharactère sera considéré comme un mot
-> WORD

-----------------------------------------------------------------------*/

int    ft_fill_tokens_list(t_data *data)
{
    int index;
    int statut;

    statut = ft_check_unclose_quote(data->read_line);
    if (statut > 0)
        return(UNCLOSED_QUOTES_ERR);
        // ft_lexer_error("Error: quotes non closed");
    index = 0;
    while (index < ft_strlen(data->read_line))
    {
        index += ft_get_word(data, index);
        index += ft_get_separators(data, index);
        index++;
    }
    return(0);
}

int    ft_lexer(t_data *data)
{
    if (ft_fill_tokens_list(data) != 0)
        return(UNCLOSED_QUOTES_ERR);
    if (!data->tokens_list)
        ft_exit(data);
    return (0);
}

// add error management : to Makefile
void    ft_minishell(t_data *data)
{
    int	error_status;

    error_status = 0;
    ft_lexer(data);
    error_status = ft_parser(data);
    if (error_status!= 0)
        ft_print_error(data, error_status);
    ft_group_tokens(data);
    ft_print_token_list(data->gp_tokens_list);
    //ft_print_token_list(data->tokens_list);
}