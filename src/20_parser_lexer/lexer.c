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

t_token *ft_fill_tokens_list(t_data *data)
{
    int index ;

    index = 0;
    
    while (data->read_line[index])
    {  
        ft_printf("index before boucle : %d\n", index);
        index += ft_get_word(data, index);
        index += ft_get_separators(data, index);
        index++;
    }
    return (data->tokens_list);
}

t_token *ft_lexer(t_data *data)
{

    data->tokens_list = NULL;
    data->tokens_list = ft_fill_tokens_list(data);
    if (data->tokens_list == NULL)
        return (NULL);
    // une fois la listes chainées remplie avec les tokens
    // Checker ici les erreurs de syntaxe
    // autres check ??
    ft_print_token_list(data->tokens_list);
    return (data->tokens_list);
}

void    ft_minishell(t_data *data)
{
    // autres checks eventuels
    if (ft_lexer(data) == NULL)
        ft_lexer_error("Error: can't create list");
    //sft_parser(data);
}
