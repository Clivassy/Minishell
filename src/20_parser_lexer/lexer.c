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
           // printf("found ' at index : %d\n", index);
           // printf("token word is : %s\n", word_token);
            exit(0);
        }
        else
        {
            printf("prout");
            exit(0);
        }
    }
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
            return (-1);
        space = ft_new_token(space_token, SPACE);
        ft_lstadd_back_token(token_list, space);
    }
    return (0);
}

// a diviser en fonction pour plus de clarté
int ft_is_not_meta(char *read_line, int index)
{
    if (read_line[index] != '|' || read_line[index] != ' '
        || read_line[index] != '\'' || read_line[index] != '\"'
        || read_line[index] != '<' || read_line[index] != '>'
        || read_line[index] != '$')
            return (0);
    else
        return (1);
}

int ft_word_len(char *read_line, int index)
{
    int len = 0;
    while (read_line[index] && read_line[index] != ' ')
    {
        len++;
        index++;
    }
    printf("%d\n", len);
    return (len);
}

int ft_is_word(t_token **token_list, char *read_line, int index)
{
    char *word_token;
    t_token *word; 
    int word_len; 

    if (ft_is_not_meta(read_line, index) == 0)
    {
        word_len = ft_word_len(read_line, index);
        word_token = ft_substr(read_line, index, word_len);
        if (!word_token)
            return (-1);
        word = ft_new_token(word_token, WORD);
        ft_lstadd_back_token(token_list, word);
    }
    return (0);
}

int ft_is_pipe(t_token **token_list, char *read_line, int index)
{
    char *pipe_token;
    t_token *pipe; 

    if (read_line[index] == '|')
    {
        pipe_token = ft_substr(read_line, index, 1);
        if (!pipe_token)
            return (-1);
      //  printf("token pipe is : '%s'\n", pipe_token);
        pipe = ft_new_token(pipe_token, PIPE);
        ft_lstadd_back_token(token_list, pipe);
       // printf("token string : %s\n", pipe->value);
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
        //i += ft_lexer_quotes(token_list, read_line, i)
        // attention, si quote, il faut bien continuer à parser a partir du charactère
        // qui suit la quote fermée. 
        ft_is_pipe(&token_list, read_line, i);
        //printf("i = %d\n", i);
        ft_is_space(&token_list, read_line, i);
        if (ft_is_word(&token_list, read_line, i) == 0)
            i += ft_word_len(read_line, i);
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

void    ft_minishell(t_data *input_minishell)
{
    t_token *token_list;
    int errno; 

    errno = 0;
    token_list = malloc(sizeof(t_token));
    token_list = ft_lexer(input_minishell->read_line, token_list);
    ft_print_token_list(token_list);
}