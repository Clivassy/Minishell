#include "minishell.h"

/*----------------------------- LEXER ------------------------------

1 ) Récupérer la string entrée en input avec readline.

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

void    ft_minishell(t_data *input_minishell)
{
    t_token *tokenizer;

    tokenizer = malloc(sizeof(t_token));
    tokenizer = ft_lexer(input_minishell->read_line, tokenizer);
}

//int ft_is word()
//{
    // tant que je parcours et que je ne tombe pas 
//}

/* Retourne la longeur du mot entre les quotes */
int ft_len_inside_quote(char *str, int index)
{
    char quote_type;
    int i;
    int len;

    if (str == NULL || str[index] == '\0')
	    return (0);
    quote_type = str[index];
    //printf("%c\n", quote_type);
    i = index + 1; 
    //printf("index = %d\n", i);
    len = 0;
    while (str[i] && str[i] != quote_type)
    {
        len++;
        i++;
    }
    if (str[i] != quote_type)
        ft_lexer_error("quote non close");
    printf("len is :%d\n", len); 
    return (len);
}

int ft_lexer_quotes(t_token *token_list, char *read_line, int index)
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
            //printf("found ' at index : %d\n", index);
            //printf("token word is : %s\n", word_token);
            exit(0);
        }
        else
        {
            printf("prout");
            exit(0);
        }
    }
    return (1);
}

t_token *ft_fill_tokens_list(char *read_line,t_token *token_list)
{
    int i;

    i =  0; 
    while (read_line[i])
    {
        // forêt de if ou je vais parcourir a la recherche des tokens 
        if (ft_lexer_quotes(token_list, read_line, i))
            printf("%d\n", i);
        //
        i++;
    }
    return (token_list);
}

t_token *ft_lexer(char *readline, t_token *token_list)
{
    token_list = ft_fill_tokens_list(readline, token_list);
    if (token_list == NULL)
        return (NULL);
    // une fois la listes chainées remplie avec les tokens
    // Checker ici les erreurs de syntaxe
    // autres check ?? 
    return (token_list);
}