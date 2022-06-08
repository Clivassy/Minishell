#include "minishell.h"
// attentio ca : ou "  cat" : bien tout r2cuperer dans un meme token.

int ft_get_mixed_token(t_token **token_list, char *read_line, int index, int len)
{
    char *word;
    t_token *word_token;

    word = ft_substr(read_line, index, len);
    word_token = ft_new_token(word, T_WORD);
    ft_lstadd_back_token(token_list, word_token);
    return(0);
}

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

int   ft_word_into_quotes(t_token **token_list, char *read_line, int index, int len)
{
    char *word;
    t_token *word_inside_quotes; 

    ft_get_quotes_token( token_list, read_line, index);
    word = ft_substr(read_line, index + 1, len);
    word_inside_quotes = ft_new_token(word, T_WORD);
    ft_lstadd_back_token(token_list, word_inside_quotes);
    index += len + 1;
    ft_get_quotes_token(token_list, read_line, index);
    return(0);
}


int ft_get_word(t_token **token_list, char *read_line, int index)
{
    char *word_token;
    t_token *word; 
    int word_len; 
    int len_inside_quotes;
    
    word_len = ft_word_len(read_line, index);
    printf("len of the word is : %d\n", word_len);
    if (read_line[index] == '\'' || read_line[index] == '\"')
    {
        if (ft_check_no_space(read_line, index, word_len, read_line[index]))
        {   
            printf("IN THE LOOP");
            printf("WORD STUCK\n");
            ft_get_mixed_token(token_list, read_line, index, word_len);
            return(word_len);
        }
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
        return(word_len);
    }
    else
        printf("No word found\n");
    return (0); 
}

