#include "minishell.h"

void    ft_fill_new_token(char *content, t_data *data, int type)
{
    t_token *new_token;

    new_token = ft_new_token(content, type);
    ft_lstadd_back_token(&data->tokens_list, new_token);
}

int ft_get_mixed_token(t_data *data, char *read_line, int index, int len)
{
    char *word;
    t_token *word_token;

    word = ft_substr(read_line, index, len);
    ft_fill_new_token(word, data, T_WORD);
    return(0);
}

int ft_get_quotes_token(t_data *data, char *read_line, int index)
{
    char *quote;
    t_token *quote_token;
    
    quote = ft_substr(read_line, index, 1);
    if (read_line[index] == '\'')
        quote_token = ft_new_token(quote, S_QUOTE);
    else 
        quote_token = ft_new_token(quote, D_QUOTE);
    ft_lstadd_back_token(&data->tokens_list, quote_token);
    return (0);
}

int   ft_word_into_quotes(t_data *data, char *read_line, int index, int len)
{
    char *word;
    t_token *word_inside_quotes; 

    ft_get_quotes_token(data, read_line, index);
    word = ft_substr(read_line, index + 1, len);
    ft_fill_new_token(word, data, T_WORD);
    index += len + 1;
    ft_get_quotes_token(data, read_line, index);
    return(0);
}

int ft_temp(char *line, int i, char quote_type);
/* Return 0 if no word ae found
Return index + word_len if a word is found */
int ft_get_word(t_data *data, int index)
{
    t_token *word;
    char *word_token; 
    char *line;
    int len_inside_quotes;
    
    line = data->read_line;
    if (line[index] == '\'' || line[index] == '\"')
    {
        if (ft_check_no_space(line, index, line[index]))
        {
            ft_get_mixed_token(data, line, index, ft_word_len(line, index));
            return(ft_word_len(line, index));
        }
        len_inside_quotes = ft_quote_word_len(line, index);
        ft_word_into_quotes(data, line, index, len_inside_quotes);
        return(len_inside_quotes + 2);
    }
    if (line[index] >= 33 && line[index] <= 126 && ft_is_word(line, index))
    {
      //  if (ft_check_non_close_quotes(line, index, line[index]) == 0)
        ///    ft_lexer_error("Error: quotes no closed");
        word_token = ft_substr(line, index, ft_word_len(line, index));
        ft_fill_new_token(word_token, data, T_WORD);
        return(ft_word_len(line, index));
    }
    return (0); 
}

