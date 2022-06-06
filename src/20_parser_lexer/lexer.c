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

t_token *ft_fill_tokens_list(char *read_line,t_token *token_list)
{
    int index ;

    index = 0;
    
    while (read_line[index])
    {  
        ft_printf("index before boucle : %d\n", index);
        index += ft_get_word(&token_list, read_line, index);
        index += ft_get_separators(&token_list, read_line, index);
        index++;
    }
    return (token_list);
}

t_token *ft_lexer(char *readline)
{
    t_token *token_list; 

    token_list = NULL;
    token_list = ft_fill_tokens_list(readline, token_list);
    if (token_list == NULL)
        return (NULL);
    // une fois la listes chainées remplie avec les tokens
    // Checker ici les erreurs de syntaxe
    // autres check ??
    ft_print_token_list(token_list);
    return (token_list);
}

void    ft_minishell(t_data *input_minishell)
{
    // autres checks eventuels
    if (ft_lexer(input_minishell->read_line) == NULL)
        ft_lexer_error("Error: can't create list");
       // ft_exit() quitter avec ft_exit
    
}
