#include "minishell.h"

/*------------------------------------------------------
Utils to : 
- Detect Dquotes / Squotes
- Detect chevrons 
- Detect heredoc
- Detect 

A RETRAVAILLER ET A METTRE AU PROPRE
-------------------------------------------------------*/

/* Retourne la longeur du mot entre les quotes */
/* int ft_len_inside_quote(char *str, int index)
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
*/

int ft_check_no_space(char *read_line, int index, int len, char c)
{
    int i;

    i = 0;
    printf("letter :%c\n",read_line[index]);
    while(i < len)
    {
        if (read_line[index] == c
            && ft_is_word(read_line, index - 1))
                return (1);
        i++;
    }
    return(0);
}

int ft_quote_word_len(char *read_line, int index)
{
    char quote_type;
    int i;
    int len;

    if (read_line == NULL || read_line[index] == '\0')
	    return (0);
    quote_type = read_line[index];
    //printf("%c\n", quote_type);
    i = index + 1; 
    //printf("index = %d\n", i);
    len = 0;
    while (read_line[i] && read_line[i] != quote_type)
    {
        len++;
        i++;
    }
    if (read_line[i] != quote_type)
        ft_lexer_error("quote non close");
    printf("len inside quote is :%d\n", len); 
    return (len);
}

int ft_is_word(char *read_line, int index)
{
    if (read_line[index] == '<' || read_line[index] == '>'
        || read_line[index] == '$'|| read_line[index] == ' ' 
        || read_line[index] == '|' )
            return(0);
    return (1);
}

int ft_word_len(char *read_line, int index)
{
    int len = 0;
    while (read_line[index])
    {
        if (read_line[index] == '<' || read_line[index] == '>'
        || read_line[index] == '$'|| read_line[index] == ' ' 
        || read_line[index] == '|' )
            return(len);
        len++;
        index++;
    }
    printf("word len :%d\n", len);
    return (len);
}