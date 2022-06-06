#include "minishell.h"

int ft_get_word(t_token **token_list, char *read_line, int index)
{
    char *word_token;
    t_token *word; 
    int word_len; 
    int len_inside_quotes;
    
    word_len = ft_word_len(read_line, index);
    if (ft_check_no_space(read_line, index, word_len))
    {
        ft_get_mixed_token(token_list, read_line, index, word_len);
        return(word_len - 1);
    }
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

