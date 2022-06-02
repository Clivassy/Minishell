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
/* int ft_get_word(t_token **token_list, char *read_line, int index)
{
    char *word_token;
    t_token *word; 
    int word_len; 
    // 
} */

/* int ft_lexer_quotes(t_token *token_list, char *read_line, int index)
{
    (void)token_list;
    char *word_token;
    int inside_quote;

    if (read_line[index] == '\'' || read_line[index] == '\"')
    {
        //printf("%s\n", read_line);
        inside_quote = ft_len_inside_quote(read_line, index);
        word_token = ft_substr(read_line, index + 1, inside_quote);
        if (read_line[index] == '\'')
        {
           // printf("found ' at index : %d\n", index);
           // printf("token word is : %s\n", word_token);
            exit(0);
        }
        elsegit s
        {
            printf("prout");
            exit(0);
        }
    }
    return (0);
} */

int ft_is_space(t_token **token_list, char *read_line, int index)
{
    char *space_token;
    t_token *space;

    if (read_line[index] == ' ' && read_line[index -1] != ' ')
    {
        space_token = ft_substr(read_line, index, 1);
        if (!space_token)
            return (-1);
        space = ft_new_token(space_token, SPACE);
        ft_lstadd_back_token(token_list, space);
    }
    return (0);
}

int ft_get_separators(t_token **token_list, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

    if (read_line[index] == ' ')
            ft_is_space(token_list, read_line, index);
    if (read_line[index] == '$' || read_line[index] == '<' ||
        read_line[index] == '>' || read_line[index] == '|')
    {
        separator = ft_substr(read_line, index, 1);
        if (!separator)
            return (-1);
        if (read_line[index] == '|')
            separator_token = ft_new_token(separator, PIPE);
        if (read_line[index] == '$')
            separator_token = ft_new_token(separator, DOLLARS);
        if (read_line[index] == '<')
            separator_token = ft_new_token(separator, REDIRECT_IN);
        if (read_line[index] == '>')
            separator_token = ft_new_token(separator, REDIRECT_OUT);
        ft_lstadd_back_token(token_list, separator_token);
    }
    return (1);
}

t_token *ft_fill_tokens_list(char *read_line,t_token *token_list)
{
    int i;

    i =  0; 
    while (read_line[i])
    {
        ft_get_separators(&token_list, read_line, i); // récup de tous les metacharactères. 
        //ft_get_words(&token_list, read_line, i);
        // attention, si quote, il faut bien continuer à parser a partir du charactère
        // qui suit la quote fermée (+ attention au cas ou bonjour"ca va" -> un seul token word)
       //if (ft_is_word(&token_list, read_line, i) == 0)
          //  i += ft_word_len(read_line, i);
        i++;
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
