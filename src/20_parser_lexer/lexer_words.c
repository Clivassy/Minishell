#include "minishell.h"

int ft_is_token_word(char *line, int index)
{
    if (!ft_is_word(line, index))
        return (0);
    return (1);
}
/*
int ft_is_token_word(char *line, int index)
{
    if ((line[index] == '\'' || line[index] == '\"') 
        || (line[index] >= 33 && line[index] <= 126) && ft_is_word(line, index))
        return (1);
    return (0);
}
*/

/* Return word len */
int ft_word_len(char *read_line, int index)
{
    int len = 0;
    while (read_line[index])
    {
        if (!ft_is_word(read_line, index))
            return(len);
        if (read_line[index] == '\"')
        {
            index++;
            len++;
            while(read_line[index] != '\"')
            {
                index++;
                len++;
            }
        }
        if (ft_is_word(read_line, index))
        {
            if (read_line[index] == '\0')
                return(len);
        }
        len++;
        index++;
    }
    return (len);
}

/* Return 1 if word into quotes is stuck with simple word */
int ft_check_no_space(char *line, int index, char c)
{
    int i;

    i = 0;    
    index++;

    while (line[index] != c)
    {
        index++;
        i++;
    }
    if (line[index + 1] == '\0')
        return (0);
    if (ft_is_word(line, index + 1))
        return (1);
    else 
        return (0);
}

int ft_get_mixed_token(t_data *data, char *read_line, int index, int len)
{
    char *word;
    t_token *word_token;

    word = ft_substr(read_line, index, len);
    if (!word)
        return (-1); // ft_exit
    ft_add_to_garbage_collector(data, word);
    ft_fill_new_token(word, data, T_WORD);
    return(0);
}

/* Return 0 if no word ae found
Return index + word_len if a word is found */
int ft_get_word(t_data *data, int index)
{
    t_token *word;
    char *word_token; 
    char *line;

    line = data->read_line;
    if (ft_is_token_word(line, index))
    {
        if (ft_check_no_space(line, index, line[index]))
        {
            ft_get_mixed_token(data, line, index, ft_word_len(line, index));
            return(ft_word_len(line, index));
        }
        word_token = ft_substr(line, index, ft_word_len(line, index));
        if (!word_token)
            return (-1); // ft_exit
        ft_add_to_garbage_collector(data, word_token);
        ft_fill_new_token(word_token, data, T_WORD);
        return(ft_word_len(line, index));
    }
    return (0); 
}
