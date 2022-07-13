#include "minishell.h"

/*----------------------------- LEXER ------------------------------

Stocker dans une liste chaînée les différents tokens.
PIPE |
REDIRECT_IN <
REDIRECT_OUT >
HEREDOC <<
D_REDIRECT_OUT >>
SPACE (all isspaces)

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
    return (0);
}