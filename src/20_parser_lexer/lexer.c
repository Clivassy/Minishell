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

/* ------------------------------------------------------------------------------------------------------------
    GET_WORD
    WORD == tout ce qui n'est pas à gérer + alphanum. 
    Etape 1 - check si readline[index] == quote
    -> si c'est le cas j'appelle ft_is_quote: pour récupérer le mot jusqu'a la fin des quotes
    tout en checkant bien qu'après la dernière quote il y a un métacharactere.

    Etape 2 - si c'est pas une dquote ou une squote
    -> je parse jusqu'a tomber sur : 
    - un métacharactère : c'est la fin du token.
    - une squote ou dquote : je stocke le début du token et l'envoie a ma fonction ft_is_quote.

    ATTENTION : la valeur de retour DOIT être la taille finale du token : car on va incrémenter i en fonction
    dans ft_fill_tokens_list. 

--------------------------------------------------------------------------------------------------------------*/
int ft_get_quotes_token(t_token **token_list, char *read_line, int index)
{
    char *quote;
    t_token *quote_token;
    
    quote = ft_substr(read_line, index, 1);
    if (read_line[index] == '\'')
        quote_token = ft_new_token(quote, S_QUOTE);
    else 
        quote_token = ft_new_token(quote, D_QUOTE);
    ft_lstadd_back_token(token_list, quote_token);
    return (0);
}

int   ft_word_into_quotes(t_token **token_list, char *read_line, int index, int len_inside_quotes)
{
    char *word;
    t_token *word_inside_quotes; 
    ft_get_quotes_token( token_list, read_line, index);
    word = ft_substr(read_line, index + 1, len_inside_quotes);
    word_inside_quotes = ft_new_token(word, T_WORD);
    ft_lstadd_back_token(token_list, word_inside_quotes);
    index += len_inside_quotes + 1;
    ft_get_quotes_token( token_list, read_line, index);
    return(0);
}

int ft_get_word(t_token **token_list, char *read_line, int index)
{
    char *word_token;
    t_token *word; 
    int word_len; 
    int len_inside_quotes;

    word_len = ft_word_len(read_line, index);
    if (read_line[index] == '\'' || read_line[index] == '\"')
    {
        ft_printf("Found quote!\n");
        len_inside_quotes = ft_quote_word_len(read_line, index);
        ft_word_into_quotes(token_list, read_line, index, len_inside_quotes);
        return(len_inside_quotes + 2);
    }
    //printf("index before word : %d\n", index);
    // printf("charactere : %c\n", read_line[index]);
    if (read_line[index] >= 33 && read_line[index] <= 126 
        && ft_is_word(read_line, index))
    {
        word_token = ft_substr(read_line, index, word_len);
        word = ft_new_token(word_token, T_WORD);
        ft_lstadd_back_token(token_list, word);
        return(word_len - 1);
    }
    else
        printf("No word found\n");
    return (0); 
}

int ft_is_space(t_token **token_list, char *read_line, int index)
{
    char *space_token;
    t_token *space;

    if (read_line[index] == ' ' && read_line[index -1] != ' ')
    {
        space_token = ft_substr(read_line, index, 1);
        if (!space_token)
            return (-1); // ft_exit 
        space = ft_new_token(space_token, T_SPACE);
        ft_lstadd_back_token(token_list, space);
    }
    return (0);
}
// FYI proto substr  : char	*ft_substr(char const *s, unsigned int start, size_t len)

int ft_is_redirect(t_token **token_list, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

    printf("index = %d\n", index);
    if (read_line[index + 1] != '<' && 
        read_line[index + 1] != '>')
    {   
        separator = ft_substr(read_line, index, 1);
        if (read_line[index] == '<')
            separator_token = ft_new_token(separator, T_REDIRECT_IN);
        else
            separator_token = ft_new_token(separator, T_REDIRECT_OUT);
        ft_lstadd_back_token(token_list, separator_token);
    }
    else if (read_line[index] == '>' && read_line[index + 1] == '>')
    {
        separator = ft_substr(read_line, index, 2);
        separator_token = ft_new_token(separator, D_REDIRECT_OUT);
        ft_lstadd_back_token(token_list, separator_token);

    }
    else if (read_line[index] == '<' && read_line[index + 1] == '<')
    {
        separator = ft_substr(read_line, index, 2);
        separator_token = ft_new_token(separator, T_HEREDOC);
        ft_lstadd_back_token(token_list, separator_token);
    }
    return (0);
}

int ft_get_separators(t_token **token_list, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

    printf("OK\n");
    printf("char : %c\n", read_line[index]);
    if (read_line[index] == ' ')
    {
        printf("this is a space!\n");
        ft_is_space(token_list, read_line, index);
        return(0);
    }
    if (read_line[index] == '<' || read_line[index] == '>')
    {
        ft_printf("is redirect!\n");
        ft_is_redirect(token_list, read_line, index);
        if (read_line[index + 1] != '<'
            || read_line[index + 1] != '>')
            return (1);
        else
            return (0);
    }      
    if (read_line[index] == '$'|| read_line[index] == '|')
    {
        separator = ft_substr(read_line, index, 1);
        if (!separator)
            return (-1);
        if (read_line[index] == '|')
            separator_token = ft_new_token(separator, T_PIPE);
        if (read_line[index] == '$')
            separator_token = ft_new_token(separator, T_DOLLARS);
        ft_lstadd_back_token(token_list, separator_token);
        return(0);
    }
    printf("no metacharactere found\n");
    return(0);
}

t_token *ft_fill_tokens_list(char *read_line,t_token *token_list)
{
    int index ;

    index =  0;
    
    while (read_line[index])
    {  
        ft_printf("index before boucle : %d\n", index);
        index += ft_get_word(&token_list, read_line, index);
        index += ft_get_separators(&token_list, read_line, index);
        index++;
        // récup de tous les metacharactères. 
        //ft_get_words(&token_list, read_line, i);
        // attention, si quote, il faut bien continuer à parser a partir du charactère
        // qui suit la quote fermée (+ attention au cas ou bonjour"ca va" -> un seul token word)
       //if (ft_is_word(&token_list, read_line, i) == 0)
          //  i += ft_word_len(read_line, i);
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
    ft_lexer(input_minishell->read_line);
    // maybe check ?
}
