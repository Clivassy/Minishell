#include "minishell.h"

int     ft_is_double_redirect(char *str, int index, char c)
{
    if (str[index] == c && str[index + 1] == c)
        return (1);
    return (0);
}

/* Return 1 if word into quotes is stuck with simple word */
int ft_check_no_space(char *line, int index, char c)
{
    int i;
    int len;

    len = ft_word_len(line, index);
    i = 0;
    while(i < len)
    {
        if (line[index] == c
            && ft_is_word(line, index - 1) 
            || ft_is_word(line, index + 1))
                return (1);
        i++;
    }
    return(0);
}

/* Return quoted word len*/
int ft_quote_word_len(char *read_line, int index)
{
    char quote_type;
    int i;
    int len;

    if (read_line == NULL || read_line[index] == '\0')
	    return (0);
    quote_type = read_line[index];
    i = index + 1; 
    len = 0;
    while (read_line[i] && read_line[i] != quote_type)
    {
        len++;
        i++;
    }
    if (read_line[i] != quote_type)
        ft_lexer_error("quote non close");
   // printf("len inside quote is :%d\n", len); 
    return (len);
}

/* Return 1 if readline token is a word (if no metachracters are found) */
int ft_is_word(char *line, int index)
{
    if (line[index] == '<' || line[index] == '>'
        || line[index] == '$'|| line[index] == ' ' 
        || line[index] == '|' )
            return(0);
    return (1);
}

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