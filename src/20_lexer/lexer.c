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
    int index;
    int statut;


    statut = ft_check_unclose_quote(data->read_line);
    if (statut > 0)
        ft_lexer_error("Error: quotes non closed");
    index = 0;
    while (index < ft_strlen(data->read_line))
    {
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
    return (data->tokens_list);
}

t_token    *ft_simulation_token_1(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_CMD;
    heretag->value = "end";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);

    return(heretag);
}

t_token    *ft_simulation_token_2(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_CMD;
    heretag->value = "§PATH";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);

    return(heretag);
}

void    ft_minishell(t_data *data)
{
    /////////////////////////////////////////
    t_token *heretag;
    heretag = ft_simulation_token_1(heretag);
    ////////////////////////////////////////
    
    /* code d'erreur retour a modifier */
    if (ft_lexer(data) == NULL)
        ft_lexer_error("Error: lexer");
    if (ft_parser(data) == ERROR)
        ft_lexer_error("Error: parser");
    ft_is_empty_list(data->tokens_list);
    if (ft_group_tokens(data) == ERROR)
        ft_lexer_error("Error: create group tokens list");
    ft_heredoc(data, heretag);
    ft_print_token_list(data->gp_tokens_list);
    //ft_print_token_list(data->tokens_list);
}