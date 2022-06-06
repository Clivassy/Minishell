#include "minishell.h"

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


int ft_is_redirect(t_token **token_list, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

    if (read_line[index] == '>' && read_line[index + 1] == '>'
    || read_line[index] == '<' && read_line[index + 1] == '<')
    {
        separator = ft_substr(read_line, index, 2);
        if (read_line[index] == '>')
            separator_token = ft_new_token(separator, D_REDIRECT_OUT);
        else 
            separator_token = ft_new_token(separator, T_HEREDOC);
        ft_lstadd_back_token(token_list, separator_token);
    }
    else
    {
        separator = ft_substr(read_line, index, 1);
        if (read_line[index] == '<')
            separator_token = ft_new_token(separator, T_REDIRECT_IN);
        else
            separator_token = ft_new_token(separator, T_REDIRECT_OUT);
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
        {
            separator_token = ft_new_token(separator, T_PIPE);
        }
        if (read_line[index] == '$')
            separator_token = ft_new_token(separator, T_DOLLARS);
        ft_lstadd_back_token(token_list, separator_token);
        return(0);
    }
    printf("no metacharactere found\n");
    return(0);
}

//SAVE 

/*int ft_is_redirect(t_token **token_list, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

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
} */