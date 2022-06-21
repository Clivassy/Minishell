#include "minishell.h"

int     ft_is_double_redirect(char *str, int index, char c)
{
    if (str[index] == c && str[index + 1] == c)
        return (1);
    return (0);
}

int ft_is_space(t_data *data, char *read_line, int index)
{
    char *space_token;
    t_token *space;

    if (read_line[index] == ' ' && read_line[index -1] != ' ')
    {
        space_token = ft_substr(read_line, index, 1);
        if (!space_token)
            ft_exit(data);
        ft_add_to_garbage_collector(data, space_token);
        space = ft_new_token(space_token, T_SPACE);
        ft_lstadd_back_token(&data->tokens_list, space);
    }
    return (0);
}

int ft_is_redirect(t_data *data, char *read_line, int index)
{
    char *separator;

    if (ft_is_double_redirect(read_line, index,read_line[index]))
    {
        separator = ft_substr(read_line, index, 2);
        if (!separator)
            ft_exit(data);
        ft_add_to_garbage_collector(data, separator);
        if (read_line[index] == '>')
            ft_fill_new_token(separator, data, D_REDIRECT_OUT);
        else 
            ft_fill_new_token(separator, data, T_HEREDOC);
    }
    else
    {
        separator = ft_substr(read_line, index, 1);
        if (!separator)
            ft_exit(data);
        ft_add_to_garbage_collector(data, separator);
        if (read_line[index] == '<')
            ft_fill_new_token(separator, data, T_REDIRECT_IN);
        else
            ft_fill_new_token(separator, data, T_REDIRECT_OUT);
    }
    return (0);
}

int ft_get_separators(t_data *data, int index)
{
    char *separator;
    char *line;

    line = data->read_line;
    if (line[index] == ' ')
        ft_is_space(data, line, index);
    if (line[index] == '<' || line[index] == '>')
    {
        ft_is_redirect(data, line, index);
            if (ft_is_double_redirect(line, index, line[index]))   
        return (1);
    }      
    if (line[index] == '|')
    {
        separator = ft_substr(line, index, 1);
        if (!separator)
            ft_exit(data);
        ft_add_to_garbage_collector(data, separator);
        ft_fill_new_token(separator, data, T_PIPE);
    }
    return(0);
}